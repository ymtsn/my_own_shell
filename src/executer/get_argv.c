#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "mosh_executer.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	get_cmd_suffix_argword_count(t_cmdlst *cmd_tree)
{
	size_t		node_count;

	node_count = get_node_count(cmd_tree, ARG_WORD);
	return (node_count);
}

char	**get_argv(t_cmdlst *cmd_tree)
{
	size_t		node_count;
	size_t		i;
	t_cmdlst	*node;
	char		**argv;

	node = cmd_tree;
	node_count = get_cmd_suffix_argword_count(node);
	argv = malloc(sizeof(char**)*(node_count + 1));
	argv[0] = get_node_value(cmd_tree, CMD_WORD);
	i = 1;
	while (node != NULL)
	{
		node = get_node_iterate(node, node, ARG_WORD);
		if (node != NULL)
		{
			argv[i] = node->value;
			i++;
		}
	}
	argv[i] = NULL;
	return (argv);
}
