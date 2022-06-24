#include "mosh_lexer.h"
#include "mosh_parser.h"
#include <stdlib.h>

t_cmdlst	*create_new_pnode(e_node_type n_type, e_token_type t_type)
{
	t_cmdlst	*pnode;

	pnode = (t_cmdlst *)malloc(sizeof(t_cmdlst));
	pnode->node_type = n_type;
	pnode->token_type = t_type;
	pnode->child = NULL;
	pnode->sibling = NULL;
	pnode->value = NULL;
	return (pnode);
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
