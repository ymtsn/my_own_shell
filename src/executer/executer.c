#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char	**environ;

void	do_execve(t_cmdlst *cmd_tree)
{
	char		**argv;
	char		*path;

	path = get_path(cmd_tree);
	argv = get_argv(cmd_tree);
	if (execve(path, argv, environ) == -1)
	{
		perror("execve error\n");
		exit(EXIT_FAILURE);
	}
}

void	simple_command_execute(t_cmdlst *cmd_tree)
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
		do_execve(cmd_tree);
	}
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error\n");
		exit (EXIT_FAILURE);
	}
}
