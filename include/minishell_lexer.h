/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:53:12 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:53:14 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LEXER_H
# define MINISHELL_LEXER_H
t_token	*lexer(char	*src);
void	init_lexer(t_lexer *lexer, char **src);
int		get_token_type(t_lexer *l, size_t chr_pos);
void	change_word_to_token(t_lexer *lexer, t_token **token);
void	set_lexer_state(t_lexer *lexer);
void	set_ionumber_len(t_lexer *lexer, int token_type);
void	set_redirecter_pipe_len(t_lexer *lexer, int token_type);
void	set_word_len(t_lexer *lexer, int token_type);
void	free_token(t_token *token);
#endif
