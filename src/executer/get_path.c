/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:55:10 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:12 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_symbol.h"
#include "minishell_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_path(t_symbol *symbol, t_cmdlst *cmdlst)
{
	char	*path;
	char	*find;
	char	*rtn;
	char	**pathlist;

	find = get_node_value(cmdlst, CMD_WORD);
	if (find == NULL)
		return (NULL);
	path = ft_strjoin("/", find);
	if (path == NULL)
		return (NULL);
	symbol = lookup_symbol(symbol, "PATH");
	if (symbol == NULL)
		return (NULL);
	pathlist = ft_split(symbol->keyval + 5, ':');
	while (*pathlist != NULL)
	{
		rtn = ft_strjoin(*pathlist, path);
		if (access(rtn, F_OK | X_OK) != -1)
			return (rtn);
		free(rtn);
		pathlist++;
	}
	return (NULL);
}
