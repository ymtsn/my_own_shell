#include "mysh_def.h"
#include "mysh_lexer.h"

void	set_ionumber_len(t_lexer *lexer, int token_type)
{
	if (token_type == IO_NUMBER_TOKEN)
	{
		while (ft_isdigit(*(lexer->src + lexer->current_pos)))
			lexer->current_pos++;
		lexer->token_type = IO_NUMBER_TOKEN;
	}
}

void	set_redirecter_pipe_len(t_lexer *lexer, int token_type)
{
	if (DLESS <= token_type && token_type <= PIPE)
	{
		lexer->current_pos++;
		if (DLESS <= token_type && token_type <= GREATAND)
			lexer->current_pos++;
		lexer->token_type = token_type;
	}
}

void	set_word_len(t_lexer *lexer, int token_type)
{
	while (token_type == WORD_TOKEN && lexer->state == READ_WORD)
	{
		lexer->current_pos++;
		token_type = get_token_type(lexer, lexer->current_pos);
		set_lexer_state(lexer);
	}
	lexer->token_type = WORD_TOKEN;
}
