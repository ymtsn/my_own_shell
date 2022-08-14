/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:57:24 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:57:27 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_executer.h"
#include "minishell_pipe.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	exec_pipe_execve(t_symbol *envl, t_cmdlst *cmdlst, size_t cmd_cnt)
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

static void	pipe_recursive(t_symbol *symbol, t_cmdlst *cmdlst, size_t cmd_cnt)
{
	pid_t	pid;
	int		fd[2];

	if (cmd_cnt == 1)
		my_execve(symbol, cmdlst);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		cmd_cnt--;
		pipe_recursive(symbol, cmdlst, cmd_cnt);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		waitpid(pid, NULL, 0);
		exec_pipe_execve(symbol, cmdlst, cmd_cnt);
	}
}

void	exec_pipe(t_symbol *symbol, t_cmdlst *cmdlst)
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
		pipe_recursive(symbol, cmdlst, cmd_count);
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error at exec_pipe");
		exit(1);
	}
}
