/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:37:35 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/02 19:39:17 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t n)
{
	char	*bufdst;
	char	*bufsrc;

	if (n == 0 || dst == src)
		return ((void *)dst);
	bufdst = (char *)dst;
	bufsrc = (char *)src;
	if (n != 0)
	{
		if (bufsrc < bufdst)
		{
			while (n--)
				*(bufdst + n) = *(bufsrc + n);
		}
		else
		{
			while (n--)
				*bufdst++ = *bufsrc++;
		}
	}
	return ((void *)dst);
}
