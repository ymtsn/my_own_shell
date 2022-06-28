#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define READ_END	0
#define WRITE_END	1

static void	do_pipe_execve(t_cmdlst	*node, size_t cmd_count)
{
	cmd_count--;
	while (cmd_count)
	{
		node = node->sibling;
		cmd_count--;
	}
	do_execve(node);
}

static size_t	get_pipe_count(t_cmdlst	*node)
{
	size_t	pipe_count;

	pipe_count = 0;
	while (node != NULL && node->node_type == PIPELINE)
	{
		node = node->sibling;
		pipe_count++;
	}
	return (pipe_count);
}

void	do_pipe_recursive(t_cmdlst *node, size_t cmd_count)
{
	pid_t	pid;
	int		fd[2];

	if (cmd_count == 1)
	{
		do_execve(node);
		perror("pipeline faile");
		exit(EXIT_FAILURE);
	}
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		cmd_count--;
		do_pipe_recursive(node, cmd_count);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		do_pipe_execve(node, cmd_count);
	}
}

void	do_pipe(t_cmdlst *cmd_tree)
{
	size_t		cmd_count;

	if (cmd_tree == NULL || cmd_tree->node_type != PIPELINE)
		return ;
	cmd_count = get_pipe_count(cmd_tree);
	do_pipe_recursive(cmd_tree, cmd_count);
}

