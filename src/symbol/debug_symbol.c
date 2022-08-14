/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:58:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:58:52 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include <stdio.h>

void	print_symbol(t_symbol *symbol)
{
	if (symbol == NULL)
		return ;
	while (symbol != NULL)
	{
		printf("%s\n", symbol->keyval);
		symbol = symbol->next;
	}
}

void	print_char_symbol(char **symbol)
{
	if (symbol == NULL)
		return ;
	while (*symbol != NULL)
	{
		printf("%s\n", *symbol);
		symbol++;
	}
	printf("%s\n", *symbol);
}
