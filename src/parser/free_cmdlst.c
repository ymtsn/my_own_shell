/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmdlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:56:29 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:56:31 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include <stdlib.h>
#include <stdio.h>

void	free_cmdlst(t_cmdlst *cmdlst)
{
	if (cmdlst == NULL)
		return ;
	if (cmdlst->sibling != NULL)
		free_cmdlst(cmdlst->sibling);
	free_cmdlst(cmdlst->child);
	free(cmdlst);
}
