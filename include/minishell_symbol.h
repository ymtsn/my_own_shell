/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_symbol.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:54:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:54:19 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SYMBOL_H
# define MINISHELL_SYMBOL_H
t_symbol	*create_symbol(void);
void		print_symbol(t_symbol *symbol);
void		print_char_symbol(char **symbol);
void		delete_symbol_keyval(t_symbol *symbol, char *keyval);
t_symbol	*make_envvar(int type, char *keyval);
int			add_symbol_keyval(t_symbol *symbol, char *keyval);
t_symbol	*lookup_symbol(t_symbol *symbol, char *find);
char		**convert_symbol_to_char(t_symbol *symbol);
#endif
