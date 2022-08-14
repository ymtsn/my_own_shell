/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:55:21 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:23 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*get_input(void)
{
	char	*src;

	src = get_next_line(1);
	while (src == NULL)
		src = get_next_line(1);
	if (src[0] == '\n')
	{
		free(src);
		return (NULL);
	}
	return (src);
}
