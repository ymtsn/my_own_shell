#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "mysh_redirect.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char	**environ;

void	my_execve(t_cmdlst *cmdlst)
{
	char		**argv;
	char		*path;

	exec_redirect(cmdlst);
	path = get_path(cmdlst);
	argv = get_argv(cmdlst);
	if (execve(path, argv, environ) == -1)
	{
		perror("execve error\n");
		exit(EXIT_FAILURE);
	}
}

void	exec_simple_command(t_cmdlst *cmd_tree)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		my_execve(cmd_tree);
	}
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error\n");
		exit (EXIT_FAILURE);
	}
}

void	executer(t_cmdlst *cmdlst)
{
	if (cmdlst->node_type == SIMPLE_COMMAND)
		exec_simple_command(cmdlst);
	if (cmdlst->node_type == PIPELINE)
		exec_pipe(cmdlst);
}
