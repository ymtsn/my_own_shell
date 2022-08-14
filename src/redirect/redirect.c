/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:57:59 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 17:02:17 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

static void	redirect_in(char *io_number, char *filename)
{
	int		redirect_fd;
	int		int_io_number;

	if (io_number != NULL)
		int_io_number = ft_atoi(io_number);
	else
		int_io_number = STDIN_FILENO;
	redirect_fd = open(filename, O_RDONLY);
	dup2(redirect_fd, int_io_number);
	close(redirect_fd);
}

static void	redirect_in_fd(char *io_number, char *filename)
{
	int		redirect_fd;
	int		int_io_number;

	if (io_number != NULL)
		int_io_number = ft_atoi(io_number);
	else
		int_io_number = STDIN_FILENO;
	redirect_fd = ft_atoi(filename);
	dup2(redirect_fd, int_io_number);
}

static void	redirect_out(char *io_number, char *filename, int append_flg)
{
	int		redirect_fd;
	int		int_io_number;

	if (io_number != NULL)
		int_io_number = ft_atoi(io_number);
	else
		int_io_number = STDOUT_FILENO;
	if (append_flg == TRUNC_FILE)
		redirect_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		redirect_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	dup2(redirect_fd, int_io_number);
	close(redirect_fd);
}

static void	redirect_out_fd(char *io_number, char *filename)
{
	int	redirect_fd;
	int	int_io_number;

	if (io_number != NULL)
		int_io_number = ft_atoi(io_number);
	else
		int_io_number = STDOUT_FILENO;
	redirect_fd = ft_atoi(filename);
	dup2(redirect_fd, int_io_number);
	close(redirect_fd);
}

void	exec_redirect(t_cmdlst *top_node)
{
	t_cmdlst	*node;
	char		*io_number;
	char		*io_file;
	char		*filename;

	node = get_node_iterate(0, top_node, IO_REDIRECT);
	while (node != NULL)
	{
		io_number = get_node_value(node, IO_NUMBER);
		io_file = get_node_value(node, IO_FILE);
		filename = get_node_value(node, FILENAME);
		if (ft_strncmp(io_file, ">>", 3) == 0)
			redirect_out(io_number, filename, APPEND_FILE);
		else if (ft_strncmp(io_file, ">&", 3) == 0)
			redirect_out_fd(io_number, filename);
		else if (ft_strncmp(io_file, "<&", 3) == 0)
			redirect_in_fd(io_number, filename);
		else if (ft_strncmp(io_file, ">", 2) == 0)
			redirect_out(io_number, filename, TRUNC_FILE);
		else if (ft_strncmp(io_file, "<", 2) == 0)
			redirect_in(io_number, filename);
		node = get_node_iterate(node->node_num, top_node, IO_REDIRECT);
	}
}
