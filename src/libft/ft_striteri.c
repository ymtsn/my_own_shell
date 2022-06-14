/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:44:57 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/07 01:24:33 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	counter;

	if (s != NULL && f != NULL)
	{
		counter = 0;
		while (*(s + counter))
		{
			f(counter, s + counter);
			counter++;
		}
	}
}
