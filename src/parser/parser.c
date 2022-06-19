#include <stddef.h>
#include "mosh_parser.h"
#include <stdio.h>

/* void	here_end(t_token *token, t_pnode *pnode)
{
}
void	io_here(t_token *token, t_pnode *pnode)
{
	here_end(token, pnode);
} */

t_pnode	*filename(t_token *token)
{
	t_pnode *pnode;

	if (token->type != WORD)
		return (NULL);
	pnode = create_new_pnode(FILENAME);
	pnode->value = token->value;
	return (pnode);
}

t_pnode	*io_file(t_token *token)
{
	t_pnode	*child;
	t_pnode *parent;
	int		type;
	int		next_type;

	if (token == NULL || token->next == NULL)
		return (NULL) ;
	type = token->type;
	next_type = token->next->type;
	if ((DLESS <= type && type <= GREAT) && (next_type == WORD))
	{
		child = filename(token->next);
		if (child == NULL)
			return (NULL);
		parent = create_new_pnode(IO_FILE);
		parent->value = token->value;
		parent->child = child;
		return (parent);
	}
	return (NULL);
}

t_pnode	*io_redirect(t_token *token)
{
	t_pnode	*child;
	t_pnode *parent;

	if (token == NULL || token->next == NULL)
		return (NULL) ;
	child = io_file(token->next);
	if (child == NULL)
		return (NULL);
	if (token->type != IO_NUMBER)
		return (child);
	parent = create_new_pnode(IO_REDIRECT);
	parent->value = token->value;
	parent->child = child;
	return (parent);
	/* io_here(token, pnode); */
}

t_pnode	*cmd_prefix(t_token **token)
{
	t_pnode	*child;
	t_pnode	*parent;
	t_pnode	*save_parent;
	size_t	size;

	child = io_redirect(*token);
	parent = create_new_pnode(CMD_PREFIX);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_pnode(CMD_PREFIX);
			parent = parent->sibling;
		}
		parent->child = child;
		size = child_listsize(child);
		while (size)
		{
			*token = (*token)->next;
			size--;
		}
		child = io_redirect(*token);
	}
	return (save_parent);
}

t_pnode *cmd_word(t_token **token)
{
	t_pnode *pnode;

	if ((*token)->type != WORD)
		return (NULL);
	pnode = create_new_pnode(CMD_WORD);
	pnode->value = (*token)->value;
	*token = (*token)->next;
	return (pnode);
}

t_pnode *word(t_token *token)
{
	t_pnode *parent;
	t_pnode *child;

	if (token == NULL || token->type != WORD)
		return (NULL);
	child = word(token->next);
	parent = create_new_pnode(CMD_WORD);
	parent->child = child;
	parent->value = token->value;
	return (parent);
}

t_pnode	*cmd_suffix(t_token **token)
{
	t_pnode	*child;
	t_pnode	*parent;
	t_pnode	*save_parent;
	size_t	size;

	child = io_redirect(*token);
	if (child == NULL)
			child = word(*token);
	parent = create_new_pnode(CMD_SUFFIX);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_pnode(CMD_SUFFIX);
			parent = parent->sibling;
		}
		parent->child = child;
		size = child_listsize(child);
		while (size)
		{
			*token = (*token)->next;
			size--;
		}
		child = io_redirect(*token);
		if (child == NULL)
			child = word(*token);
	}
	return (save_parent);
}

t_pnode	*simple_command(t_token **token)
{
	t_pnode	*parent;

	parent = create_new_pnode(SIMPLE_COMMAND);
	parent->child = cmd_prefix(token);
	parent->sibling = create_new_pnode(SIMPLE_COMMAND);
	parent->sibling->child = cmd_word(token);
	parent->sibling->sibling =  create_new_pnode(SIMPLE_COMMAND);
	parent->sibling->sibling->child = cmd_suffix(token);
	return (parent);
}

t_pnode	*pipeline(t_token **token)
{
	t_pnode	*parent;
	parent = simple_command(token);
	return (parent);
}

void	parser(t_token **token)
{
	t_pnode *parser;
	parser = pipeline(token);
	print_pnode(parser);
}

