/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:36:15 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/06 16:52:47 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(char *s1, size_t size)
{
	char	*buf;
	char	*save;
	char	*temp;

	if (s1 == NULL)
		return (NULL);
	buf = (char *)ft_calloc(1, ft_strlen(s1) + size);
	if (buf == NULL)
		return (NULL);
	save = buf;
	temp = s1;
	while (*s1)
		*buf++ = *s1++;
	free(temp);
	return (save);
}
