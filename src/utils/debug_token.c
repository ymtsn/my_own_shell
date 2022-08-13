#include "mysh_def.h"
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
		if (!ft_strncmp(token->value, "\n", 2) && \
			!ft_strncmp(token_table[token->type], "\n", 2))
		{
			printf("value:\e[33m%s\e[0m ", "new_line");
			printf("token_type:\e[31m%s\e[0m\n", "new_line");
		}
		else
		{
			printf("value:\e[33m%s\e[0m ", token->value);
			printf("token_type:\e[31m%s\e[0m\n", token_table[token->type]);
		}
		token = token->next;
	}
}

void	print_token(t_token *token)
{
	char	token_table[14][10];

	set_token_table(token_table);
	printf("++-- \e[3myour tokenlst\e[0m --++\n");
	do_print_token(token, token_table);
}
