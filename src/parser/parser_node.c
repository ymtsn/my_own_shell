#include "mosh_parser.h"
#include <stdlib.h>
#include <stdio.h>

t_pnode	*create_new_pnode(e_node_type type)
{
	t_pnode	*pnode;

	pnode = (t_pnode *)malloc(sizeof(t_pnode));
	pnode->node_type = type;
	pnode->child = NULL;
	pnode->sibling = NULL;
	pnode->value = NULL;
	return (pnode);
}

size_t	child_listsize(t_pnode *lst)
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

void	print_pnode(t_pnode *pnode)
{
	t_pnode	*sibling;
	t_pnode	*sibling_child;

	sibling = pnode;
	while (sibling != NULL)
	{
		sibling_child = sibling->child;
		while (sibling_child != NULL)
		{
			printf("value:\t%s\n", sibling_child->value);
			sibling_child = sibling_child->child;
		}
		sibling = sibling->sibling;
	}
}
