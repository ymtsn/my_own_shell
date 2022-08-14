/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:59:07 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:59:08 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "libft.h"
#include <stdio.h>

static size_t	get_keylen(char *keyval)
{
	size_t	count;

	if (keyval == NULL)
		return (0);
	count = 0;
	while (*keyval)
	{
		if (*keyval == '=')
			return (count);
		keyval++;
		count++;
	}
	return (0);
}

t_symbol	*lookup_symbol(t_symbol *symbol, char *find)
{
	size_t	chrpos;

	if (symbol == NULL || find == NULL)
		return (NULL);
	while (symbol != NULL)
	{
		chrpos = get_keylen(symbol->keyval);
		if (symbol->keyval != NULL)
			if (!ft_strncmp(symbol->keyval, find, chrpos))
				return (symbol);
		symbol = symbol->next;
	}
	return (NULL);
}
