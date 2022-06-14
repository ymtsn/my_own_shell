/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:38 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/01 23:28:59 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_delimitarcnt(const char *s, char delim)
{
	size_t	delimcnt;

	delimcnt = 0;
	while (*s)
	{
		if (*s != delim)
		{
			while (*s != delim && *s)
				s++;
			delimcnt++;
		}
		if (*s)
			s++;
	}
	return (delimcnt);
}

static int	ft_setstr(char **buf, char const **s, char delim, size_t rowcnt)
{
	char const	*end;
	char const	*begin;

	begin = *s;
	while (*begin != '\0' && *begin == delim)
		begin++;
	end = begin;
	while (*end != '\0' && *end != delim)
		end++;
	*s = end;
	*(buf + rowcnt) = ft_substr(begin, 0, end - begin);
	if (*(buf + rowcnt) == NULL)
		return (0);
	return (1);
}

static void	ft_setfree(char **buf, size_t rowcnt)
{
	while (rowcnt != 0)
	{
		free(*(buf + rowcnt));
		rowcnt--;
	}
	free(*buf);
	free(buf);
}

char	**ft_split(char const *s, char delim)
{
	char	**buf;
	size_t	delimcnt;
	size_t	rowcnt;

	if (s == NULL)
		return (NULL);
	delimcnt = ft_delimitarcnt(s, delim);
	buf = (char **)malloc(sizeof(char *) * (delimcnt + 1));
	if (buf == NULL)
		return (NULL);
	rowcnt = 0;
	while (rowcnt != delimcnt)
	{
		if (!ft_setstr(buf, &s, delim, rowcnt))
		{
			ft_setfree(buf, rowcnt);
			return (NULL);
		}
		rowcnt++;
	}
	*(buf + rowcnt) = NULL;
	return (buf);
}
