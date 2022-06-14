/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:51:55 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/02 19:40:03 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstbuf;
	char	*srcbuf;

	if (n == 0 || dst == src)
		return (dst);
	dstbuf = (char *)dst;
	srcbuf = (char *)src;
	while (n--)
		*dstbuf++ = *srcbuf++;
	return ((void *)dst);
}
