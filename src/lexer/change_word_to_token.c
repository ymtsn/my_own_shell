/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_word_to_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:55:31 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:33 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "libft.h"
#include <stdio.h>
#include <stddef.h>

static t_token	*create_new_token(t_lexer *lexer)
{
	int		len;
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		perror("malloc fail at create_new_token");
		exit(EXIT_FAILURE);
	}
	new_token->next = NULL;
	new_token->type = lexer->token_type;
	new_token->parse_done_flg = NOT_PARSE;
	len = lexer->current_pos - lexer->word_start_pos;
	new_token->value = ft_substr(lexer->src, lexer->word_start_pos, len);
	return (new_token);
}

void	change_word_to_token(t_lexer *lexer, t_token **token)
{
	t_token	*buf;

	if (lexer->state == STRING_END)
		return ;
	if (*token == NULL)
	{
		*token = create_new_token(lexer);
		return ;
	}
	buf = *token;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = create_new_token(lexer);
}
