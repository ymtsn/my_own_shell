/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:07:55 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/31 23:43:44 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi_skip(char **str)
{
	long	buf;
	int		sign;

	sign = 1;
	while (ft_isspace(**str))
		(void)(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(void)(*str)++;
	}
	buf = 0;
	while (ft_isdigit(**str))
		buf = buf * 10 + (*(*str)++ - '0');
	return ((int)(buf * sign));
}
