/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:54:43 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:54:45 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_symbol.h"
#include "minishell_executer.h"
#include "minishell_pipe.h"
#include "minishell_redirect.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	my_execve(t_symbol *symbol, t_cmdlst *cmdlst)
{
	char	**argv;
	char	*path;
	char	**my_environ;

	exec_redirect(cmdlst);
	path = get_path(symbol, cmdlst);
	argv = get_argv(cmdlst);
	my_environ = convert_symbol_to_char(symbol);
	if (execve(path, argv, my_environ) == -1)
	{
		perror("execve error");
		exit(EXIT_FAILURE);
	}
}

void	exec_simple_command(t_symbol *symbol, t_cmdlst *cmdlist)
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
		my_execve(symbol, cmdlist);
	}
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid error");
		exit (EXIT_FAILURE);
	}
}

void	executer(t_symbol *symbol, t_cmdlst *cmdlst)
{
	if (cmdlst->node_type == SIMPLE_COMMAND)
		exec_simple_command(symbol, cmdlst);
	if (cmdlst->node_type == PIPELINE)
		exec_pipe(symbol, cmdlst);
}
