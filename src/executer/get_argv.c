#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**get_argv(t_cmdlst *cmd_tree)
{
	size_t		node_count;
	size_t		i;
	t_cmdlst	*node;
	char		**argv;

	node = cmd_tree;
	node_count = get_node_count(cmd_tree, ARG_WORD);
	argv = malloc(sizeof(char**)*(node_count + 1));
	argv[0] = get_node_value(cmd_tree, CMD_WORD);
	i = 1;
	while (node != NULL)
	{
		node = get_node_iterate(node->node_num, node, ARG_WORD);
		if (node != NULL)
		{
			argv[i] = node->value;
			i++;
		}
	}
	argv[i] = NULL;
	return (argv);
}
