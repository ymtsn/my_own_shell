#include "mosh_lexer.h"
#include "libft.h"
#define WHITE_SPACE 1
#define READING_WORD 2
#define STRING_END 3
#define ERROR 4

static void	set_lexer_state(t_lexer *lexer)
{
	char	ch;

	ch = lexer->src[lexer->current_pos];
	if (ch == '\0')
		lexer->state = STRING_END;
	else if (('\t' <= ch && ch <= '\r') || ch == ' ')
		lexer->state = WHITE_SPACE;
	else
		lexer->state = READING_WORD;
}

static void	init_lexer(t_lexer *lexer, char **src)
{
	lexer->current_pos = 0;
	lexer->word_start_pos = 0;
	lexer->src = *src;
	set_lexer_state(lexer);
}

static void	skip_whitespace(t_lexer *lexer)
{
	if (lexer->state != WHITE_SPACE)
		return ;
	while (lexer->state == WHITE_SPACE)
	{
		lexer->current_pos++;
		set_lexer_state(lexer);
	}
}

static void	get_word_width(t_lexer *lexer)
{
	if (lexer->state != READING_WORD)
		return ;
	lexer->word_start_pos = lexer->current_pos;
	while (lexer->state == READING_WORD)
	{
		lexer->current_pos++;
		set_lexer_state(lexer);
	}
}

t_token	*lexer(char *src)
{
	t_lexer	lexer;
	t_token	*token_list;

	token_list = NULL;
	init_lexer(&lexer, &src);
	while (lexer.state != STRING_END)
	{
		skip_whitespace(&lexer);
		get_word_width(&lexer);
		change_word_to_token(&lexer, &token_list);
	}
	return (token_list);
}
