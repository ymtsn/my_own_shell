/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_symbol_to_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:58:34 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:58:36 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	get_totalsize(t_symbol *symbol)
{
	size_t	count;

	count = 0;
	while (symbol != NULL)
	{
		if (symbol->variable_type == env_variable)
			count++;
		symbol = symbol->next;
	}
	return (count);
}

char	**convert_symbol_to_char(t_symbol *symbol)
{
	size_t	total_list;
	char	**rtn;
	char	**save;

	total_list = 0;
	total_list = get_totalsize(symbol);
	rtn = malloc(sizeof(char **) * (total_list + 1));
	if (rtn == NULL)
	{
		perror("malloc fail at convert_envrist_to_char");
		exit(EXIT_FAILURE);
	}
	save = rtn;
	while (symbol != NULL)
	{
		if (symbol->variable_type == env_variable)
		{
			*rtn = symbol->keyval;
			rtn++;
		}
		symbol = symbol->next;
	}
	rtn = NULL;
	return (save);
}
