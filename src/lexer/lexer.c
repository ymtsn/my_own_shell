#include "mysh_lexer.h"
#include "libft.h"
#define WHITE_SPACE 1
#define READ_WORD 2
#define STRING_END 3
#define IO_NUM_POSSIBLE 4
#define ERROR 5
#include <stdio.h>

int	get_token_type(t_lexer *l, size_t chr_pos)
{
	int			i;
	int			rs;
	const char	*find;
	int			degit_flg;

	degit_flg = 0;
	while (ft_isdigit(*(l->src + chr_pos)))
	{
		chr_pos++;
		degit_flg = 1;
	}
	i = 0;
	while (i <= PIPE)
	{
		find = (const char*)(l->src + chr_pos);
		rs = ft_strncmp(find, l->token_table[i], ft_strlen(l->token_table[i]));
		if (!rs && degit_flg && DLESS <= i && i <= GREAT)
			return (IO_NUMBER_TOKEN);
		else if (!degit_flg && rs == 0)
			return (i);
		i++;
	}
	return (WORD_TOKEN);
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

static void	get_word_len_and_token_type(t_lexer *lexer)
{
	int	token_type;

	if (lexer->state != READ_WORD)
		return ;
	lexer->word_start_pos = lexer->current_pos;
	token_type = get_token_type(lexer, lexer->current_pos);
	if (token_type == IO_NUMBER_TOKEN)
	{
		while (ft_isdigit(*(lexer->src + lexer->current_pos)))
			lexer->current_pos++;
		lexer->token_type = IO_NUMBER_TOKEN;
		set_lexer_state(lexer);
		return ;
	}
	if (DLESS <= token_type && token_type <= PIPE)
	{
		lexer->current_pos++;
		if (DLESS <= token_type && token_type <= GREATAND)
			lexer->current_pos++;
		lexer->token_type = token_type;
		set_lexer_state(lexer);
		return ;
	}
	while (token_type == WORD_TOKEN && lexer->state == READ_WORD)
	{
		lexer->current_pos++;
		token_type = get_token_type(lexer, lexer->current_pos);
		set_lexer_state(lexer);
	}
	lexer->token_type = WORD_TOKEN;
}

t_token	*lexer(char *src)
{
	t_lexer	lexer;
	t_token	*token;

	if (src == NULL)
		return (NULL);
	token = NULL;
	init_lexer(&lexer, &src);
	while (lexer.state != STRING_END)
	{
		skip_whitespace(&lexer);
		if (lexer.state != STRING_END)
		{
			get_word_len_and_token_type(&lexer);
			change_word_to_token(&lexer, &token);
		}
	}
	return (token);
}
