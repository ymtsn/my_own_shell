/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:05:58 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/02 19:04:42 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*target1;
	unsigned char	*target2;

	target1 = (unsigned char *)s1;
	target2 = (unsigned char *)s2;
	while (n--)
	{
		if (*target1 != *target2)
			return ((int)*target1 - (int)*target2);
		target1++;
		target2++;
	}
	return (0);
}
