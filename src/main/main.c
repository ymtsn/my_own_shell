/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:56:18 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:56:20 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_symbol.h"
#include "minishell_prompt.h"
#include "minishell_get_input.h"
#include "minishell_lexer.h"
#include "minishell_parser.h"
#include "minishell_utils.h"
#include "minishell_executer.h"
#include "libft.h"
#include <stdlib.h>

static void	free_variables(char *src, t_token *tkn, t_cmdlst *cmd)
{
	free(src);
	free_token(tkn);
	free_cmdlst(cmd);
}

static void	cmdline_loop(void)
{
	t_symbol	*symbol;
	char		*src;
	t_token		*tokenlst;
	t_cmdlst	*cmdlst;

	symbol = create_symbol();
	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			tokenlst = lexer(src);
			cmdlst = parser(tokenlst);
			if (check_debug_mode(cmdlst))
				debug_print(tokenlst, cmdlst);
			else
				executer(symbol, cmdlst);
			free_variables(src, tokenlst, cmdlst);
		}
	}
}

int	main(void)
{
	cmdline_loop();
	return (0);
}
