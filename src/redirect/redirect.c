#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_redirect.h"
#include "mysh_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#define TRUNC_FILE	0
#define APPEND_FILE	1

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

void	exec_redirect(t_cmdlst *node)
{
	t_cmdlst	*io_redirect;
	char		*io_number;
	char		*io_file;
	char		*filename;

	io_redirect = get_node_iterate(0, node, IO_REDIRECT);
	while (io_redirect != NULL)
	{
		io_number = get_node_value(io_redirect, IO_NUMBER);
		io_file = get_node_value(io_redirect, IO_FILE);
		filename = get_node_value(io_redirect, FILENAME);
		if (ft_strncmp(io_file, ">>", 2) == 0)
			redirect_out(io_number, filename, APPEND_FILE);
		else if (ft_strncmp(io_file, ">&", 2) == 0)
			redirect_out_fd(io_number, filename);
		else if (ft_strncmp(io_file, "<&", 2) == 0)
			redirect_in_fd(io_number, filename);
		else if (ft_strncmp(io_file, ">", 2) == 0)
			redirect_out(io_number, filename, TRUNC_FILE);
		else if (ft_strncmp(io_file, "<", 2) == 0)
			redirect_in(io_number, filename);
		io_redirect = get_node_iterate(io_redirect->node_num, node, IO_REDIRECT);
	}
}
