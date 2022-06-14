/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:52:23 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/15 12:49:11 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	mylist = (t_list *)malloc(sizeof(t_list) * 1);
	if (mylist == NULL)
		return (NULL);
	mylist->content = content;
	mylist->next = NULL;
	return (mylist);
}
