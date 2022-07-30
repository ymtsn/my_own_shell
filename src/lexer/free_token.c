#include "libft.h"
#include "mysh_lexer.h"

void	free_token(t_token *token)
{
	t_token	*buf;

	if (token == NULL)
		return ;
	while (token != NULL)
	{
		buf = token;
		token = token->next;
		free(buf->value);
		free(buf);
	}
}

