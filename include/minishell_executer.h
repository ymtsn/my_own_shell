/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executer.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:52:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:52:52 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTER_H
# define MINISHELL_EXECUTER_H
char	*get_path(t_symbol *symbol, t_cmdlst *cmdlist);
char	**get_argv(t_cmdlst *cmdlist);
void	my_execve(t_symbol *symbol, t_cmdlst *cmdlist);
void	exec_simple_command(t_symbol *symbol, t_cmdlst *cmdlist);
void	executer(t_symbol *symbol, t_cmdlst *cmdlst);
#endif
