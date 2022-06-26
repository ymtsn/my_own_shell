#include "mosh_lexer.h"
#include "mosh_parser.h"
#include <stdio.h>
#include <stdlib.h>

t_cmdlst	*create_new_node(e_node_type n_type, e_token_type t_type)
{
	t_cmdlst	*node;

	node = (t_cmdlst *)malloc(sizeof(t_cmdlst));
	node->node_num = 0;
	node->node_type = n_type;
	node->token_type = t_type;
	node->child = NULL;
	node->sibling = NULL;
	node->value = NULL;
	return (node);
}

size_t	set_childnode_number(t_cmdlst *node, size_t node_number)
{
	if (node == NULL)
		return (node_number - 1);
	node->node_num = node_number;
	node_number = set_childnode_number(node->child, node_number + 1);
	if (node->sibling != NULL)
		node_number = set_childnode_number(node->sibling, node_number + 1);
	return (node_number);
}

void	set_node_number(t_cmdlst *node)
{
	(void)set_childnode_number(node, 0);
}

size_t	child_listsize(t_cmdlst *lst)
{
	size_t	len;

	if (lst == NULL)
		return (0);
	len = 0;
	while (lst != NULL)
	{
		lst = lst->child;
		len++;
	}
	return (len);
}
