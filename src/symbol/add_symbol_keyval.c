/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_symbol_keyval.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:58:27 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:58:29 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_symbol.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
int	add_symbol_keyval(t_symbol *symbol, char *keyval)
{
	if (symbol == NULL || keyval == NULL)
		return (FAIL);
	if (lookup_symbol(symbol, keyval) != NULL)
		return (FAIL);
	while (symbol->next != NULL)
		symbol = symbol->next;
	symbol->next = make_envvar(env_variable, keyval);
	symbol->next->prev = symbol;
	return (SUCCESS);
}
