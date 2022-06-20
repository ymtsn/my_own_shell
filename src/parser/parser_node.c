#include "mosh_parser.h"
#include <stdlib.h>

t_pnode	*create_new_pnode(e_node_type n_type, e_token_type t_type)
{
	t_pnode	*pnode;

	pnode = (t_pnode *)malloc(sizeof(t_pnode));
	pnode->node_type = n_type;
	pnode->token_type = t_type;
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
