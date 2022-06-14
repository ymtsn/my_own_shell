/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:13:56 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/17 20:16:27 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;
	t_list	*temp;

	if (lst == NULL)
		return ;
	buf = *lst;
	while (buf != NULL)
	{
		temp = buf;
		buf = buf->next;
		if (del != NULL)
			del((void *)temp->content);
		free(temp);
	}
	*lst = NULL;
}
