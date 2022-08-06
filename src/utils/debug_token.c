#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_utils.h"
#include "libft.h"
#include <stdio.h>

static void	set_token_table(char token_table[14][10])
{
	(void)ft_strlcpy(token_table[DLESS], "<<", 3);
	(void)ft_strlcpy(token_table[DGREAT], ">>", 3);
	(void)ft_strlcpy(token_table[DGREATAND], ">>&", 4);
	(void)ft_strlcpy(token_table[GREATAND], ">&", 3);
	(void)ft_strlcpy(token_table[LESSAND], "<&", 3);
	(void)ft_strlcpy(token_table[ANDGREAT], "&>", 3);
	(void)ft_strlcpy(token_table[ASSIGNMENT_WORD], "=", 2);
	(void)ft_strlcpy(token_table[NEWLINE], "\n", 2);
	(void)ft_strlcpy(token_table[PIPE], "|", 2);
	(void)ft_strlcpy(token_table[LESS], "<", 2);
	(void)ft_strlcpy(token_table[GREAT], ">", 2);
	(void)ft_strlcpy(token_table[IO_NUMBER_TOKEN], "io_number", 10);
	(void)ft_strlcpy(token_table[NAME], "name", 5);
	(void)ft_strlcpy(token_table[WORD_TOKEN], "word", 5);
}

void	do_print_token(t_token *token, char token_table[14][10])
{

	while (token != NULL)
	{
		if (!ft_strncmp(token->value,"\n",2) && !ft_strncmp(token_table[token->type],"\n",2))
		{
			printf("value:\t%s\n", "new_line");
			printf("token_type:\t%s\n", "new_line");
		}
		else
		{
			printf("value:\t%s\n", token->value);
			printf("token_type:\t%s\n", token_table[token->type]);
		}
		token = token->next;
	}
}

void	print_token(t_token *token)
{
	char	token_table[14][10];

	set_token_table(token_table);
	do_print_token(token, token_table);
}
