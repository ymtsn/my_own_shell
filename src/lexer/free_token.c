/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:55:41 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:55:43 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "libft.h"

void	free_token(t_token *token)
{
	t_token	*buf;

	if (token == NULL)
		return ;
	while (token != NULL)
	{
		buf = token;
		token = token->next;
		free(buf->value);
		free(buf);
	}
}
