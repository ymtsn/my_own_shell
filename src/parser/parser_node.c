#include "mosh_lexer.h"
#include "mosh_parser.h"
#include <stdlib.h>

t_cmdlst	*create_new_pnode(e_node_type n_type, e_token_type t_type)
{
	t_cmdlst	*pnode;

	pnode = (t_cmdlst *)malloc(sizeof(t_cmdlst));
	pnode->node_num = 0;
	pnode->node_type = n_type;
	pnode->token_type = t_type;
	pnode->child = NULL;
	pnode->sibling = NULL;
	pnode->value = NULL;
	return (pnode);
}

static size_t	set_childnode_number(t_cmdlst *node, size_t node_number)
{
	if (node == NULL)
		return (node_number - 1);
	node->node_num = node_number;
	node_number = set_childnode_number(node->child, node_number + 1);
	return (node_number);
}

static size_t	set_siblingnode_number(t_cmdlst *node, size_t node_number)
{
	while (node != NULL)
	{
		node_number = set_childnode_number(node, node_number);
		if (node != NULL)
		{
			node_number++;
			node = node->sibling;
		}
	}
	return (node_number);
}

void	set_node_number(t_cmdlst *node)
{
	size_t	node_number;

	node_number = 1;
	while (node != NULL)
	{
		node_number = set_siblingnode_number(node->child, node_number);
		if (node != NULL)
		node = node->sibling;
	}
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
