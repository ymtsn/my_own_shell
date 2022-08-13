#include "mysh_def.h"
#include "mysh_parser.h"

static t_cmdlst	*filename(t_token *token, int suffix_flg)
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

static t_cmdlst	*io_file(t_token *token, int suffix_flg)
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

static t_cmdlst	*io_number(t_token *token, int suffix_flg)
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
