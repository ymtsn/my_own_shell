/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:03:43 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/03 08:46:45 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	newlst = NULL;
	while (lst != NULL && f != NULL)
	{
		temp = ft_lstnew((void *)lst->content);
		if (temp == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		temp->content = f(temp->content);
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}
