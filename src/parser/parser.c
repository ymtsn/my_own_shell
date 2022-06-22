#include <stddef.h>
#include "mosh_parser.h"
#include "mosh_debug.h"
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

	if (token == NULL || token->type != WORD_TOKEN)
		return (NULL);
	pnode = create_new_pnode(FILENAME, token->type);
	pnode->value = token->value;
	return (pnode);
}

t_pnode	*io_file(t_token *token)
{
	t_pnode	*child;
	t_pnode *parent;

	if (token == NULL)
		return (NULL) ;
	if (DLESS <= token->type && token->type <= GREAT)
	{
		child = filename(token->next);
		if (child == NULL)
			return (NULL);
		parent = create_new_pnode(IO_FILE, token->type);
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

	if (token == NULL)
		return (NULL) ;
	if (token->type == IO_NUMBER)
		child = io_file(token->next);
	else
		child = io_file(token);
	if (child == NULL || token->type != IO_NUMBER)
		return (child);
	parent = create_new_pnode(IO_REDIRECT, token->type);
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
	parent = create_new_pnode(CMD_PREFIX, NONE);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_pnode(CMD_PREFIX, NONE);
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

	if ((*token)->type != WORD_TOKEN)
		return (NULL);
	pnode = create_new_pnode(CMD_WORD, (*token)->type);
	pnode->value = (*token)->value;
	*token = (*token)->next;
	return (pnode);
}

t_pnode *word(t_token *token)
{
	t_pnode *parent;
	t_pnode *child;

	if (token == NULL ||  token->type != WORD_TOKEN)
		return (NULL);
	child = word(token->next);
	parent = create_new_pnode(WORD, token->type);
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
	parent = create_new_pnode(CMD_SUFFIX, NONE);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_pnode(CMD_SUFFIX, NONE);
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

	parent = create_new_pnode(SIMPLE_COMMAND, NONE);
	parent->child = cmd_prefix(token);
	parent->sibling = create_new_pnode(SIMPLE_COMMAND, NONE);
	parent->sibling->child = cmd_word(token);
	parent->sibling->sibling =  create_new_pnode(SIMPLE_COMMAND, NONE);
	parent->sibling->sibling->child = cmd_suffix(token);
	return (parent);
}

t_pnode	*pipeline(t_token **token)
{
	t_pnode	*parent;
	t_pnode	*save_parent;

	parent = create_new_pnode(PIPELINE, NONE);
	save_parent = parent;
	parent->child = simple_command(token);
	while (*token != NULL && (*token)->type == PIPE)
	{
		parent->sibling = create_new_pnode(PIPELINE, NONE);
		parent = parent->sibling;
		*token = (*token)->next;
		parent->child = simple_command(token);
	}
	return (save_parent);
}

void	parser(t_token **token)
{
	t_pnode *parser;
	parser = pipeline(token);
	print_pnode(parser);
}

