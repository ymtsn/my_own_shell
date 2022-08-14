/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:54:26 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:54:28 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H
void		print_cmdlst(t_cmdlst *cmdlst);
void		print_token(t_token *token);
int			check_debug_mode(t_cmdlst *cmdlst);
void		debug_print(t_token *token, t_cmdlst *cmdlst);
char		*get_node_value(t_cmdlst *cmdlst, int type);
size_t		get_node_count(t_cmdlst *cmdlst, int type);
t_cmdlst	*get_node(t_cmdlst *cmdlst, int type);
t_cmdlst	*get_node_iterate(size_t node_num, t_cmdlst *cmdlst, int type);
#endif
