#include "mysh_lexer.h"
#include "libft.h"
#include <stdio.h>

void	print_token(t_token *token, t_lexer *lexer)
{
	const char	*value;
	char 		*type;

	while (token != NULL)
	{
		value = token->value;
		type = lexer->token_table[token->type];
		if (!ft_strncmp(value,"\n",2) && !ft_strncmp(type,"\n",2))
		{
			printf("value:\t%s\n", "new_line");
			printf("token_type:\t%s\n", "new_line");
		}
		else
		{
			printf("value:\t%s\n", value);
			printf("token_type:\t%s\n", type);
		}
		token = token->next;
	}
}

static void	set_lexer_token_table(t_lexer *lexer)
{
	(void)ft_strlcpy(lexer->token_table[DLESS], "<<", 3);
	(void)ft_strlcpy(lexer->token_table[DGREAT], ">>", 3);
	(void)ft_strlcpy(lexer->token_table[DGREATAND], ">>&", 4);
	(void)ft_strlcpy(lexer->token_table[GREATAND], ">&", 3);
	(void)ft_strlcpy(lexer->token_table[LESSAND], "<&", 3);
	(void)ft_strlcpy(lexer->token_table[ANDGREAT], "&>", 3);
	(void)ft_strlcpy(lexer->token_table[ASSIGNMENT_WORD], "=", 2);
	(void)ft_strlcpy(lexer->token_table[NEWLINE], "\n", 2);
	(void)ft_strlcpy(lexer->token_table[PIPE], "|", 2);
	(void)ft_strlcpy(lexer->token_table[LESS], "<", 2);
	(void)ft_strlcpy(lexer->token_table[GREAT], ">", 2);
	(void)ft_strlcpy(lexer->token_table[IO_NUMBER_TOKEN], "io_number", 10);
	(void)ft_strlcpy(lexer->token_table[NAME], "name", 5);
	(void)ft_strlcpy(lexer->token_table[WORD_TOKEN], "word", 5);
}

void	init_lexer(t_lexer *lexer, char **src)
{
	lexer->current_pos = 0;
	lexer->word_start_pos = 0;
	lexer->src = *src;
	set_lexer_token_table(lexer);
	set_lexer_state(lexer);
}
