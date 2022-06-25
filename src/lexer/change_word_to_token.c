#include "mosh_lexer.h"
#include "libft.h"

static t_token	*create_new_token(t_lexer *lexer)
{
	int		len;
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	new_token->next = NULL;
	new_token->type = lexer->token_type;
	len = lexer->current_pos - lexer->word_start_pos;
	new_token->value = ft_substr(lexer->src, lexer->word_start_pos, len);
	return (new_token);
}

void	change_word_to_token(t_lexer *lexer, t_token **token)
{
	t_token	*buf;

	if (*token == NULL)
	{
		*token = create_new_token(lexer);
		return ;
	}
	buf = *token;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = create_new_token(lexer);
}
