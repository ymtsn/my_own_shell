/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:21:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/07 10:16:27 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buf;
	size_t			counter;

	if (s == NULL || f == NULL)
		return (NULL);
	counter = 0;
	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	while (*s)
	{
		*(buf + counter) = f(counter,*s);
		counter++;
		s++;
	}
	*(buf + counter) = '\0';
	return (buf);
}
