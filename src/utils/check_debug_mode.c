/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_debug_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:00:35 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 17:02:56 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_utils.h"
#include "libft.h"
#include <stdio.h>

int	check_debug_mode(t_cmdlst *cmd_top)
{
	t_cmdlst	*suffix;

	if (cmd_top == NULL)
		return (0);
	while (cmd_top->sibling != NULL)
		cmd_top = cmd_top->sibling;
	suffix = get_node(cmd_top, CMD_SUFFIX);
	while (suffix->child != NULL)
		suffix = suffix->child;
	if (suffix != NULL && suffix->value != NULL)
		if (ft_strncmp((const char *)suffix->value, \
		(const char *)"--debug", 8) == 0)
			return (1);
	return (0);
}

void	debug_print(t_token *token, t_cmdlst *cmdlst)
{
	print_token(token);
	print_cmdlst(cmdlst);
}
