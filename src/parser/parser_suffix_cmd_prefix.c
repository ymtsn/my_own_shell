#include "mysh_def.h"
#include "mysh_parser.h"

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

	if (token == NULL || token->type != WORD_TOKEN)
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
