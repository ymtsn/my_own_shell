/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:55:53 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:54 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "libft.h"
#include <stdio.h>

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
	lexer->state = LEXER_INIT;
	lexer->src = *src;
	set_lexer_token_table(lexer);
}
