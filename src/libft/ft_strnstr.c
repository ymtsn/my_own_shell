/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:19:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/30 22:05:20 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *stk, const char *ndl, size_t len)
{
	size_t	cnt;

	if (!*ndl)
		return ((char *)stk);
	while (len && *stk)
	{
		cnt = 0;
		while ((*(stk + cnt) == *(ndl + cnt)) && cnt < len)
		{
			cnt++;
			if (*(ndl + cnt) == '\0')
				return ((char *)stk);
			if (*(stk + cnt) == '\0')
				return (NULL);
		}
		stk++;
		len--;
	}
	return (NULL);
}
