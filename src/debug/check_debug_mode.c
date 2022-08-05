#include "libft.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_debug.h"
#include <stdio.h>

int		check_debug_mode(t_cmdlst *cmd_top)
{
	t_cmdlst	*suffix;
	t_cmdlst	*save;

	if (cmd_top == NULL)
		return (0);
	while (cmd_top->sibling != NULL)
		cmd_top = cmd_top->sibling;
	suffix = get_node_iterate(cmd_top->node_num, cmd_top, ARG_WORD);
	while (suffix != NULL)
	{
		save = suffix;
		suffix = get_node_iterate(suffix->node_num, cmd_top, ARG_WORD);
	}
	if (save != NULL && save->value != NULL)
		if (ft_strncmp((const char*)save->value, \
		(const char*)"--debug", 7) == 0)
			return (1);
	return (0);
}

void	debug_print(t_token *token, t_cmdlst *cmdlst)
{
	print_token(token);
	print_cmdlst(cmdlst);
}
