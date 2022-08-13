#include "mysh_lexer.h"
#include "mysh_parser.h"
#include <stdio.h>
#include <stdlib.h>

t_cmdlst	*create_new_node(e_node_type n_type, e_token_type t_type)
{
	t_cmdlst	*node;

	node = (t_cmdlst *)malloc(sizeof(t_cmdlst));
	if (node == NULL)
	{
		perror("malloc fail at create_new_node");
		exit(EXIT_FAILURE);
	}
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

void	skip_parsed_token(t_token **token)
{
	while (*token != NULL && (*token)->parse_done_flg == PARSE_DONE)
		*token = (*token)->next;
}
