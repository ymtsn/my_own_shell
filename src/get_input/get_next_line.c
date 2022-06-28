/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:28:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/06/27 19:08:36 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "get_next_line.h"

int	ft_howoutput(char **stock, char **rtn, int INFO)
{
	size_t	npos;
	size_t	len;
	char	*temp;

	npos = 0;
	len = ft_strlen(*stock);
	while (len && *(*stock + npos++) != '\n')
		len--;
	if (len == 0)
		npos = 0;
	if ((npos == ft_strlen(*stock) || !npos) && INFO == NOREAD)
		return (ALLOUTPUT);
	if (!npos)
		return (DONOTHING);
	temp = *stock;
	*rtn = ft_substr(*stock, 0, npos);
	*stock = ft_substr(*stock, npos, ft_strlen(*stock + npos));
	free(temp);
	if (*rtn == NULL || *stock == NULL)
	{
		free(*rtn);
		free(*stock);
		return (ERROR);
	}
	return (SPLITSTOCK);
}

int	ft_join_stck_rd(char **stock, char **readbuf, int INFO)
{
	char	*buf;
	char	*temp;
	size_t	len;

	len = ft_strlen(*readbuf) + ft_strlen(*stock);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL || INFO == ERROR || len == 0)
	{
		free(buf);
		free(*stock);
		free(*readbuf);
		return (ERROR);
	}
	temp = *stock;
	while (*stock != NULL && **stock)
		*buf++ = *(*stock)++;
	free(temp);
	temp = *readbuf;
	while (*readbuf != NULL && **readbuf)
		*buf++ = *(*readbuf)++;
	free(temp);
	*buf = '\0';
	buf -= len;
	*stock = buf;
	return (INFO);
}

int	ft_make_readbuf(int fd, char **readbuf)
{
	ssize_t	readlen;

	*readbuf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (*readbuf == NULL)
		return (ERROR);
	readlen = read(fd, *readbuf, BUFFER_SIZE);
	if (readlen < 0 || readlen == 0)
	{
		free(*readbuf);
		*readbuf = NULL;
	}
	if (readlen < 0)
		return (ERROR);
	if (readlen == 0)
		return (NOREAD);
	*(*(readbuf) + readlen) = '\0';
	return (CONTINUE);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	static int	INFO;
	char		*readbuf;
	char		*rtn;

	if (fd < 0 || fd >= GUACA_FDMAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (INFO != ERROR && INFO != ALLOUTPUT)
	{
		if (INFO != NOREAD)
		{
			INFO = ft_make_readbuf(fd, &readbuf);
			INFO = ft_join_stck_rd(&stock, &readbuf, INFO);
		}
		if (INFO == ERROR)
			return (NULL);
		INFO = ft_howoutput(&stock, &rtn, INFO);
		if (INFO == ALLOUTPUT)
			return (stock);
		if (INFO == SPLITSTOCK)
			return (rtn);
	}
	return (NULL);
}
