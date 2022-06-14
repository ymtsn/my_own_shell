/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:35:03 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/07 09:49:24 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = ft_strlen(src);
	if (dstsize == 0)
		return (counter);
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (counter);
}
