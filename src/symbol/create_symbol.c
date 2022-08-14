/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:58:42 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:58:44 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;

t_symbol	*make_envvar(int type, char *keyval)
{
	t_symbol	*new;

	new = malloc(sizeof(t_symbol));
	if (new == NULL)
	{
		perror("malloc fail at make_env");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->next = NULL;
	new->variable_type = type;
	if (keyval == NULL)
		return (new);
	new->keyval = ft_strdup((const char *)keyval);
	if (new->keyval == NULL)
	{
		perror("ft_strdup fail at make_env");
		exit(EXIT_FAILURE);
	}
	return (new);
}

t_symbol	*create_symbol(void)
{
	t_symbol	*symbol;
	t_symbol	*save;

	if (environ == NULL)
		return (NULL);
	symbol = make_envvar(head, NULL);
	save = symbol;
	while (*environ != NULL)
	{
		symbol->next = make_envvar(env_variable, *environ);
		symbol->next->prev = symbol;
		symbol = symbol->next;
		environ++;
	}
	return (save);
}
