/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:03:42 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/01 20:56:02 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*olddst;
	const char	*oldsrc;
	size_t		dstlen;

	olddst = (const char *)dst;
	oldsrc = src;
	while (dstsize && *dst)
	{
		dst++;
		dstsize--;
	}
	dstlen = dst - olddst;
	if (dstsize == 0)
		return ((size_t)(dstlen + ft_strlen(src)));
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	while (*src)
		src++;
	return ((size_t)(dstlen + (src - oldsrc)));
}
