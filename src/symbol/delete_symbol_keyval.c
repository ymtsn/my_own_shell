/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_symbol_keyval.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:58:58 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:58:59 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_symbol.h"
#include <stdlib.h>
#include <stdio.h>

void	delete_symbol_keyval(t_symbol *symbol, char *find)
{
	t_symbol	*target;

	if (symbol == NULL || find == NULL)
		return ;
	target = lookup_symbol(symbol, find);
	if (target == NULL)
		return ;
	if (target->prev != NULL)
		target->prev->next = target->next;
	if (target->next != NULL)
		target->next->prev = target->prev;
	free(target->keyval);
	free(target);
}
