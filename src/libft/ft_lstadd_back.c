/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:29:26 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/14 14:23:49 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (lst == NULL || new == NULL)
		return ;
	buf = *lst;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = new;
	}
}
