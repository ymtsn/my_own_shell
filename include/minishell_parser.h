/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:53:22 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:53:24 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_H
# define MINISHELL_PARSER_H
t_cmdlst	*parser(t_token *token);
t_cmdlst	*cmd_suffix(t_token *token);
t_cmdlst	*cmd_prefix(t_token *token);
t_cmdlst	*cmd_word(t_token *token);
t_cmdlst	*word(t_token *token);
t_cmdlst	*io_redirect(t_token *token, int suffix_flg);
t_cmdlst	*io_here(t_token *token, int suffix_flg);
t_cmdlst	*create_new_node(t_node_type node_type, t_token_type token_type);
void		set_node_number(t_cmdlst *cmdlst);
void		skip_parsed_token(t_token **token);
void		free_cmdlst(t_cmdlst *cmdlst);
#endif
