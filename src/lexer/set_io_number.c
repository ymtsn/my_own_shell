#include "mosh_lexer.h"
#include "libft.h"

static int	find_redirect(int type)
{
	if (type == DLESS || type == DGREAT || type == LESSAND \
	|| type == GREATAND || type == LESS || type == GREAT)
		return (1);
	return (0);
}

static int	find_io_number(char* val)
{
	while (ft_isdigit(*val))
		val++;
	if (!*val)
		return (1);
	return (0);
}

void	set_io_number(t_token *token)
{
	if (token == NULL)
		return ;
 	while (token->next != NULL)
	{
		if (find_io_number(token->value) && find_redirect(token->next->type))
			token->type = IO_NUMBER;
		token = token->next;
	}
}

