#include <stddef.h>
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include <stdio.h>

/* void	here_end(t_token *token)
{
}
void	io_here(t_token *token)
{
	here_end(token, node);
} */

void	skip_parsed_token(t_token **token)
{
	while (*token != NULL && (*token)->parse_done_flg == PARSE_DONE)
		*token = (*token)->next;
}

t_cmdlst	*filename(t_token *token, int suffix_flg)
{
	t_cmdlst	*parent;

	if (token == NULL || token->type != WORD_TOKEN)
		return (NULL);
	parent = create_new_node(FILENAME, token->type);
	parent->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	parent->child = io_redirect(token->next, suffix_flg);
	if (suffix_flg == DO_SUFFIX && parent->child == NULL)
		parent->child = word(token->next);
	return (parent);
}

t_cmdlst	*io_file(t_token *token, int suffix_flg)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL) ;
	if (DLESS <= token->type && token->type <= GREAT)
	{
		child = filename(token->next, suffix_flg);
		if (child == NULL)
			return (NULL);
		parent = create_new_node(IO_FILE, token->type);
		parent->value = token->value;
		token->parse_done_flg = PARSE_DONE;
		parent->child = child;
		return (parent);
	}
	return (NULL);
}

t_cmdlst	*io_number(t_token *token, int suffix_flg)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL);
	child = io_file(token->next, suffix_flg);
	if (child == NULL)
		return (NULL);
	parent = create_new_node(IO_NUMBER, token->type);
	parent->child = child;
	parent->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	return (parent);
}

t_cmdlst	*io_redirect(t_token *token, int suffix_flg)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL)
		return (NULL);
	if (token->type == IO_NUMBER_TOKEN)
		child = io_number(token, suffix_flg);
	else
		child = io_file(token, suffix_flg);
	if (child == NULL)
		return (child);
	parent = create_new_node(IO_REDIRECT, NONE);
	parent->child = child;
	return (parent);
	/* io_here(token, node); */
}

t_cmdlst	*cmd_prefix(t_token *token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	parent = create_new_node(CMD_PREFIX, NONE);
	child = io_redirect(token, DO_PREFIX);
	parent->child = child;
	return (parent);
}

t_cmdlst	*cmd_word(t_token *token)
{
	t_cmdlst	*node;

	node = create_new_node(CMD_WORD, WORD_TOKEN);
	if (token->type != WORD_TOKEN)
		return (node);
	node->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	return (node);
}

t_cmdlst	*word(t_token *token)
{
	t_cmdlst	*parent;

	if (token == NULL ||  token->type != WORD_TOKEN)
		return (NULL);
	parent = create_new_node(ARG_WORD, token->type);
	parent->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	parent->child = word(token->next);
	if (parent->child == NULL)
		parent->child = io_redirect(token->next, DO_SUFFIX);
	return (parent);
}

t_cmdlst	*cmd_suffix(t_token *token)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	parent = create_new_node(CMD_SUFFIX, NONE);
	child = io_redirect(token, DO_SUFFIX);
	if (child == NULL)
		child = word(token);
	parent->child = child;
	return (parent);
}

t_cmdlst	*simple_command(t_token **token)
{
	t_cmdlst	*prefix;
	t_cmdlst	*command;
	t_cmdlst	*suffix;

	prefix = cmd_prefix(*token);
	skip_parsed_token(token);
	command = cmd_word(*token);
	skip_parsed_token(token);
	suffix = cmd_suffix(*token);
	skip_parsed_token(token);
	prefix->sibling = command;
	command->sibling = suffix;
	return (prefix);
}

t_cmdlst	*pipeline(t_token *token)
{
	t_cmdlst	*parent;
	t_cmdlst	*save_parent;

	parent = create_new_node(SIMPLE_COMMAND, NONE);
	save_parent = parent;
	parent->child = simple_command(&token);
	while (token != NULL && token->type == PIPE)
	{
		parent->node_type = PIPELINE;
		token = token->next;
		parent->sibling = create_new_node(PIPELINE, NONE);
		parent = parent->sibling;
		parent->child = simple_command(&token);
	}
	return (save_parent);
}

t_cmdlst	*parser(t_token *token)
{
	t_cmdlst	*parser;

	if (token == NULL)
		return (NULL);
	parser = pipeline(token);
	set_node_number(parser);
	return (parser);
}
