/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:19:21 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/17 18:01:29 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(const char c, const char *set)
{
	while (*set)
		if ((unsigned char)c == (unsigned char)*(set++))
			return (1);
	return (0);
}

static char	*ft_isbegin(const char *s, const char *set)
{
	if (*s && *set)
	{
		while (ft_isset(*s, set))
			s++;
	}
	return ((char *)s);
}

static char	*ft_isend(const char *s, const char *set)
{
	size_t	len;

	len = ft_strlen(s);
	if (*s && *set)
	{
		s = s + len - 1;
		while (len && ft_isset(*s, set))
		{
			s--;
			len--;
		}
		s = s + 1;
		return ((char *)s);
	}
	if (*s)
		s = s + len;
	return ((char *)s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	len;
	size_t	n;
	char	*begin;
	char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	n = 0;
	begin = ft_isbegin(s1, set);
	end = ft_isend(s1, set);
	if (end - begin > 0)
		len = end - begin;
	else
		len = 0;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	*(buf + len) = '\0';
	while (len-- > 0)
	{
		*(buf + n) = *(begin + n);
		n++;
	}
	return (buf);
}
