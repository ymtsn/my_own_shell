/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:55:52 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/01 13:35:47 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (new == NULL || lst == NULL)
		return ;
	buf = new;
	while (buf->next != NULL)
		buf = buf->next;
	buf->next = *lst;
	*lst = new;
}
