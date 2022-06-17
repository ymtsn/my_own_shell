#include "mosh_lexer.h"
#include "libft.h"
#include <stdio.h>

void	print_token(t_token *token)
{
	while (token != NULL)
	{
		printf("%s\n", token->value);
		printf("%d\n", token->type);
		token = token->next;
	}
}

static void	set_lexer_token_table(t_lexer *lexer)
{
	(void)ft_strlcpy(lexer->token_table[DLESS], "<<",3);
	(void)ft_strlcpy(lexer->token_table[DGREAT], ">>",3);
	(void)ft_strlcpy(lexer->token_table[LESSAND], "<&",3);
	(void)ft_strlcpy(lexer->token_table[GREATAND], ">&",3);
	(void)ft_strlcpy(lexer->token_table[ASSIGNMENT_WORD], "=\0",3);
	(void)ft_strlcpy(lexer->token_table[NEWLINE], "\n\0",3);
	(void)ft_strlcpy(lexer->token_table[PIPE], "|\0",3);
	(void)ft_strlcpy(lexer->token_table[LESS], "<\0",3);
	(void)ft_strlcpy(lexer->token_table[GREAT], ">\0",3);
}

void	init_lexer(t_lexer *lexer, char **src)
{
	lexer->current_pos = 0;
	lexer->word_start_pos = 0;
	lexer->src = *src;
	set_lexer_token_table(lexer);
	set_lexer_state(lexer);
}
