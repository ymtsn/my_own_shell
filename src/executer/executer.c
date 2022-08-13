#include "mysh_envlst.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "mysh_redirect.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	my_execve(t_envlst *envlst, t_cmdlst *cmdlst)
{
	char	**argv;
	char	*path;
	char	**my_environ;

	exec_redirect(cmdlst);
	path = get_path(envlst, cmdlst);
	argv = get_argv(cmdlst);
	my_environ = convert_envlst_to_char(envlst);
	if (execve(path, argv, my_environ) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
}

void	exec_simple_command(t_envlst *envlst, t_cmdlst *cmdlist)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		my_execve(envlst, cmdlist);
	}
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error");
		exit (EXIT_FAILURE);
	}
}

void	executer(t_envlst *envlst, t_cmdlst *cmdlst)
{
	if (cmdlst->node_type == SIMPLE_COMMAND)
		exec_simple_command(envlst, cmdlst);
	if (cmdlst->node_type == PIPELINE)
		exec_pipe(envlst, cmdlst);
}
