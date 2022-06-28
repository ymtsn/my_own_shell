#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	get_node_count(t_cmdlst *node, int find_type)
{
	size_t node_count;
	node_count = 0;

	while (node != NULL)
	{
		node = get_node_iterate(node->node_num, node, find_type);
		if (node != NULL)
			node_count++;
	}
	return (node_count);
}

char *get_node_value(t_cmdlst *cmd_tree, int find_type)
{
	t_cmdlst	*node;

	node = get_node(cmd_tree, find_type);
	if (node == NULL)
		return (NULL);
	return (node->value);
}

t_cmdlst	*get_node(t_cmdlst *node, int find_type)
{
	int			node_type;
	t_cmdlst	*rtn_node;

	while (node != NULL)
	{
		node_type = node->node_type;
		if (find_type == node_type)
			return (node);
		else
			rtn_node = get_node(node->child, find_type);
		if (rtn_node != NULL)
			return(rtn_node);
		node = node->sibling;
	}
	return (NULL);
}

t_cmdlst	*get_node_iterate(size_t find_root_num, t_cmdlst *node, int find_type)
{
	int			node_type;
	t_cmdlst	*rtn_node;

	while (node != NULL)
	{
		node_type = node->node_type;
		if (find_type == node_type && find_root_num < node->node_num)
			return (node);
		else
			rtn_node = get_node_iterate(find_root_num, node->child, find_type);
		if (rtn_node != NULL)
			return(rtn_node);
		node = node->sibling;
	}
	return (NULL);
}
