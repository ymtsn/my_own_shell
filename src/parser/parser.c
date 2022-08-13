#include "mysh_def.h"
#include "mysh_parser.h"
#include <stdio.h>

t_cmdlst	*here_end(t_token *token, int suffix_flg)
{
	t_cmdlst	*parent;

	if (token == NULL || token->type != WORD_TOKEN)
		return (NULL);
	parent = create_new_node(HERE_END, WORD_TOKEN);
	parent->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	parent->child = io_redirect(token->next, suffix_flg);
	if (suffix_flg == DO_SUFFIX && parent->child == NULL)
		parent->child = word(token->next);
	return (parent);
}

t_cmdlst	*io_here(t_token *token, int suffix_flg)
{
	t_cmdlst	*child;
	t_cmdlst	*parent;

	if (token == NULL || token->type != DLESS)
		return (NULL);
	child = here_end(token->next, suffix_flg);
	if (child == NULL)
		return (NULL);
	parent = create_new_node(IO_HERE, DLESS);
	parent->value = token->value;
	token->parse_done_flg = PARSE_DONE;
	parent->child = child;
	return (parent);
}

t_cmdlst	*filename(t_token *token, int suffix_flg)
{
	t_cmdlst	*parent;

	if (token == NULL || token->type != WORD_TOKEN)
		return (NULL);
	parent = create_new_node(FILENAME, WORD_TOKEN);
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

	if (token != NULL && (DGREAT <= token->type && token->type <= GREAT))
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

	if (token == NULL || token->type != IO_NUMBER_TOKEN)
		return (NULL);
	child = io_file(token->next, suffix_flg);
	if (child == NULL)
		child = io_here(token->next, suffix_flg);
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
	child = io_number(token, suffix_flg);
	if (child == NULL)
		child = io_file(token, suffix_flg);
	if (child == NULL)
		child = io_here(token, suffix_flg);
	if (child == NULL)
		return (NULL);
	parent = create_new_node(IO_REDIRECT, NONE);
	parent->child = child;
	return (parent);
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
	t_cmdlst	*rtn;

	prefix = cmd_prefix(*token);
	skip_parsed_token(token);
	command = cmd_word(*token);
	skip_parsed_token(token);
	suffix = cmd_suffix(*token);
	skip_parsed_token(token);
	prefix->sibling = command;
	command->sibling = suffix;
	rtn = create_new_node(SIMPLE_COMMAND, NONE);
	rtn->child = prefix;
	return (rtn);
}

void	pipeline(t_token **token, t_cmdlst *cmdlst)
{
	cmdlst->node_type = PIPELINE;
	while (cmdlst != NULL && *token != NULL && (*token)->type == PIPE)
	{
		*token = (*token)->next;
		cmdlst->sibling = simple_command(token);
		cmdlst->sibling->node_type = PIPELINE;
		cmdlst = cmdlst->sibling;
	}
}

t_cmdlst	*make_cmdlst(t_token *token)
{
	t_cmdlst	*cmdlst;

	cmdlst = simple_command(&token);
	if (cmdlst != NULL && token != NULL && token->type == PIPE)
		pipeline(&token, cmdlst);
	return (cmdlst);
}

t_cmdlst	*parser(t_token *token)
{
	t_cmdlst	*parser;

	if (token == NULL)
		return (NULL);
	parser = make_cmdlst(token);
	set_node_number(parser);
	return (parser);
}
