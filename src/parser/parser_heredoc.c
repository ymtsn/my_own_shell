#include "mysh_def.h"
#include "mysh_parser.h"

static t_cmdlst	*here_end(t_token *token, int suffix_flg)
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
