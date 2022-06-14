/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:20:42 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/01 07:48:08 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	char	*save;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	save = buf;
	while (*s1)
		*buf++ = *s1++;
	while (*s2)
		*buf++ = *s2++;
	*buf = '\0';
	return (save);
}
