/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atos_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:07:55 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/04/01 19:00:03 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

size_t	ft_atos_skip(char **str)
{
	size_t	buf;

	while (ft_isspace(**str))
		(void)(*str)++;
	if (**str == '-' || **str == '+')
		(void)(*str)++;
	buf = 0;
	while (ft_isdigit(**str))
		buf = buf * 10 + (*(*str)++ - '0');
	return (buf);
}
