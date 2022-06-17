#include "mosh_lexer.h"
#include "libft.h"
#define WHITE_SPACE 1
#define READ_WORD 2
#define READ_OPERATOR_WORD 3
#define STRING_END 4
#define ERROR 5

int	get_token_type(t_lexer *l, size_t chr_pos)
{
	int			i;
	int			result;
	const char	*find;

	i = 0;
	while (i <= GREAT)
	{
		find = (const char*)(l->src + chr_pos);
		result = ft_strncmp(find, l->token_table[i], ft_strlen(l->token_table[i]));
		if (result == 0)
			return (i);
		i++;
	}
	return (WORD);
}

void	set_lexer_state(t_lexer *lexer)
{
	char	ch;

	ch = lexer->src[lexer->current_pos];
	if (ch == '\0')
		lexer->state = STRING_END;
	else if (ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r' || ch == ' ')
		lexer->state = WHITE_SPACE;
	else
		lexer->state = READ_WORD;
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

static void	get_word_info(t_lexer *lexer)
{
	int	token_type;
	if (lexer->state != READ_WORD)
		return ;
	lexer->word_start_pos = lexer->current_pos;
	token_type = get_token_type(lexer, lexer->current_pos);
	if (token_type != WORD)
	{
		if (DLESS <= token_type && token_type <= GREATAND)
			lexer->current_pos = lexer->current_pos + 2;
		else
			lexer->current_pos++;
		lexer->token_type = token_type;
		set_lexer_state(lexer);
		return ;
	}
	while (token_type == WORD && lexer->state == READ_WORD)
	{
		lexer->current_pos++;
		token_type = get_token_type(lexer, lexer->current_pos);
		set_lexer_state(lexer);
	}
	lexer->token_type = WORD;
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
		get_word_info(&lexer);
		change_word_to_token(&lexer, &token_list);
	}
	return (token_list);
}
