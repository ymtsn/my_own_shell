/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:23:00 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/01 07:42:36 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*targetstr;

	targetstr = (unsigned char *)s;
	while (n--)
	{
		if (*targetstr == (unsigned char)c)
			return ((void *)targetstr);
		targetstr++;
	}
	return (NULL);
}
