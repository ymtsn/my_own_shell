/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:01:14 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 17:01:15 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_utils.h"
#include "libft.h"
#include <stdio.h>

size_t	get_node_count(t_cmdlst *node, int find_type)
{
	size_t	node_count;

	node_count = 0;
	while (node != NULL)
	{
		node = get_node_iterate(node->node_num, node, find_type);
		if (node != NULL)
			node_count++;
	}
	return (node_count);
}

char	*get_node_value(t_cmdlst *cmdlst, int find_type)
{
	t_cmdlst	*node;

	if (cmdlst == NULL)
		return (NULL);
	node = get_node(cmdlst, find_type);
	if (node == NULL)
		return (NULL);
	return (node->value);
}

t_cmdlst	*get_node(t_cmdlst *node, int find_type)
{
	int			node_type;
	t_cmdlst	*rtn_node;

	while (node != NULL)
	{
		node_type = node->node_type;
		if (find_type == node_type)
			return (node);
		else
			rtn_node = get_node(node->child, find_type);
		if (rtn_node != NULL)
			return (rtn_node);
		node = node->sibling;
	}
	return (NULL);
}

t_cmdlst	*get_node_iterate(size_t root_num, t_cmdlst *node, int find_type)
{
	t_cmdlst	*rtn_node;

	while (node != NULL)
	{
		if (find_type == (int)node->node_type && root_num < node->node_num)
			return (node);
		else
			rtn_node = get_node_iterate(root_num, node->child, find_type);
		if (rtn_node != NULL)
			return (rtn_node);
		node = node->sibling;
	}
	return (NULL);
}
