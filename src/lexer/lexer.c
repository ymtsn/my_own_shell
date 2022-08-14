/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:56:08 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:56:10 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_lexer.h"
#include "libft.h"
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
		find = (const char *)(l->src + chr_pos);
		rs = ft_strncmp(find, l->token_table[i], ft_strlen(l->token_table[i]));
		if (!rs && !degit_flg)
			return (i);
		if (!rs && degit_flg && DLESS <= i && i <= GREAT)
			return (IO_NUMBER_TOKEN);
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
	set_lexer_state(lexer);
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
		set_ionumber_len(lexer, token_type);
	if (DLESS <= token_type && token_type <= PIPE)
		set_redirecter_pipe_len(lexer, token_type);
	if (token_type == WORD_TOKEN)
		set_word_len(lexer, token_type);
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
		get_word_len_and_token_type(&lexer);
		change_word_to_token(&lexer, &token);
	}
	return (token);
}
