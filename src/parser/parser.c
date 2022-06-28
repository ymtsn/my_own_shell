#include <stddef.h>
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_debug.h"
#include <stdio.h>

/* void	here_end(t_token *token, t_cmdlst *node)
{
}
void	io_here(t_token *token, t_cmdlst *node)
{
	here_end(token, node);
} */

t_cmdlst	*filename(t_token *token)
{
	t_cmdlst *node;

	if (token == NULL || token->type != WORD_TOKEN)
		return (NULL);
	node = create_new_node(FILENAME, token->type);
	node->value = token->value;
	return (node);
}

t_cmdlst	*io_file(t_token *token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL) ;
	if (DLESS <= token->type && token->type <= GREAT)
	{
		child = filename(token->next);
		if (child == NULL)
			return (NULL);
		parent = create_new_node(IO_FILE, token->type);
		parent->value = token->value;
		parent->child = child;
		return (parent);
	}
	return (NULL);
}

t_cmdlst	*io_number(t_token *token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL);
	child = io_file(token->next);
	if (child == NULL)
		return (NULL);
	parent = create_new_node(IO_NUMBER, token->type);
	parent->child = child;
	parent->value = token->value;
	return (parent);
}

t_cmdlst	*io_redirect(t_token *token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL);
	if (token->type == IO_NUMBER_TOKEN)
		child = io_number(token);
	else
		child = io_file(token);
	if (child == NULL)
		return (child);
	parent = create_new_node(IO_REDIRECT, NONE);
	parent->child = child;
	return (parent);
	/* io_here(token, node); */
}

t_cmdlst	*cmd_prefix(t_token **token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;
	t_cmdlst	*save_parent;
	size_t		size;

	child = io_redirect(*token);
	parent = create_new_node(CMD_PREFIX, NONE);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_node(CMD_PREFIX, NONE);
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

t_cmdlst	*cmd_word(t_token **token)
{
	t_cmdlst	*node;

	if ((*token)->type != WORD_TOKEN)
		return (NULL);
	node = create_new_node(CMD_WORD, (*token)->type);
	node->value = (*token)->value;
	*token = (*token)->next;
	return (node);
}

t_cmdlst	*word(t_token *token)
{
	t_cmdlst	*parent;
	t_cmdlst	*child;

	if (token == NULL ||  token->type != WORD_TOKEN)
		return (NULL);
	child = word(token->next);
	parent = create_new_node(ARG_WORD, token->type);
	parent->child = child;
	parent->value = token->value;
	return (parent);
}

t_cmdlst	*cmd_suffix(t_token **token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;
	t_cmdlst	*save_parent;
	size_t		size;

	child = io_redirect(*token);
	if (child == NULL)
			child = word(*token);
	parent = create_new_node(CMD_SUFFIX, NONE);
	save_parent = parent;
	while (child != NULL)
	{
		if (parent->child != NULL)
		{
			parent->sibling = create_new_node(CMD_SUFFIX, NONE);
			parent = parent->sibling;
		}
		parent->child = child;
		size = child_listsize(child);
		while (*token != NULL && size)
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

t_cmdlst	*simple_command(t_token **token)
{
	t_cmdlst	*parent;

	parent = create_new_node(CMD_PREFIX_HEAD, NONE);
	parent->child = cmd_prefix(token);
	parent->sibling = create_new_node(CMD_WORD_HEAD, NONE);
	parent->sibling->child = cmd_word(token);
	parent->sibling->sibling =  create_new_node(CMD_SUFFIX_HRAD, NONE);
	parent->sibling->sibling->child = cmd_suffix(token);
	return (parent);
}

t_cmdlst	*pipeline(t_token **token)
{
	t_cmdlst	*parent;
	t_cmdlst	*save_parent;

	parent = create_new_node(SIMPLE_COMMAND, NONE);
	save_parent = parent;
	parent->child = simple_command(token);
	while (*token != NULL && (*token)->type == PIPE)
	{
		parent->node_type = PIPELINE;
		*token = (*token)->next;
		parent->sibling = create_new_node(PIPELINE, NONE);
		parent = parent->sibling;
		parent->child = simple_command(token);
	}
	return (save_parent);
}

t_cmdlst	*parser(t_token **token)
{
	t_cmdlst	*parser;

	parser = pipeline(token);
	set_node_number(parser);
	return (parser);
}

