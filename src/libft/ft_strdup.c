/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:18:23 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/29 23:24:26 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	counter;
	size_t	len;

	len = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	counter = 0;
	while (len--)
		*(buf + counter++) = *s1++;
	*(buf + counter) = '\0';
	return (buf);
}
