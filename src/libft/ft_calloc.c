/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:04:31 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/02 18:40:08 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	s = (char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return ((void *)s);
}
