#include "mysh_def.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	exec_pipe_execve(t_envlst *envl, t_cmdlst *cmdlst, size_t cmd_cnt)
{
	cmd_cnt--;
	while (cmd_cnt)
	{
		cmdlst = cmdlst->sibling;
		cmd_cnt--;
	}
	my_execve(envl, cmdlst);
}

static size_t	get_pipe_count(t_cmdlst	*cmdlst)
{
	size_t	pipe_count;

	pipe_count = 0;
	while (cmdlst != NULL && cmdlst->node_type == PIPELINE)
	{
		cmdlst = cmdlst->sibling;
		pipe_count++;
	}
	return (pipe_count);
}

static void	pipe_recursive(t_envlst *envlst, t_cmdlst *cmdlst, size_t cmd_cnt)
{
	pid_t	pid;
	int		fd[2];

	if (cmd_cnt == 1)
		my_execve(envlst, cmdlst);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		cmd_cnt--;
		make_pipe_recursive(envlst, cmdlst, cmd_cnt);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		waitpid(pid, NULL, 0);
		exec_pipe_execve(envlst, cmdlst, cmd_cnt);
	}
}

void	exec_pipe(t_envlst *envlst, t_cmdlst *cmdlst)
{
	size_t		cmd_count;
	pid_t		pid;
	int			status;

	if (cmdlst == NULL || cmdlst->node_type != PIPELINE)
		return ;
	cmd_count = get_pipe_count(cmdlst);
	pid = fork();
	if (pid < 0)
	{
		perror("fork error at exec_pipe");
		exit(1);
	}
	else if (pid == 0)
		pipe_recursive(envlst, cmdlst, cmd_count);
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error at exec_pipe");
		exit(1);
	}
}
