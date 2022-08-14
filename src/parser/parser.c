/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:57:13 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/08/14 16:57:15 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_def.h"
#include "minishell_parser.h"
#include <stdio.h>

t_cmdlst	*simple_command(t_token **token)
{
	t_cmdlst	*prefix;
	t_cmdlst	*command;
	t_cmdlst	*suffix;
	t_cmdlst	*rtn;

	prefix = cmd_prefix(*token);
	skip_parsed_token(token);
	command = cmd_word(*token);
	skip_parsed_token(token);
	suffix = cmd_suffix(*token);
	skip_parsed_token(token);
	prefix->sibling = command;
	command->sibling = suffix;
	rtn = create_new_node(SIMPLE_COMMAND, NONE);
	rtn->child = prefix;
	return (rtn);
}

void	pipeline(t_token **token, t_cmdlst *cmdlst)
{
	cmdlst->node_type = PIPELINE;
	while (cmdlst != NULL && *token != NULL && (*token)->type == PIPE)
	{
		*token = (*token)->next;
		cmdlst->sibling = simple_command(token);
		cmdlst->sibling->node_type = PIPELINE;
		cmdlst = cmdlst->sibling;
	}
}

t_cmdlst	*make_cmdlst(t_token *token)
{
	t_cmdlst	*cmdlst;

	cmdlst = simple_command(&token);
	if (cmdlst != NULL && token != NULL && token->type == PIPE)
		pipeline(&token, cmdlst);
	return (cmdlst);
}

t_cmdlst	*parser(t_token *token)
{
	t_cmdlst	*parser;

	if (token == NULL)
		return (NULL);
	parser = make_cmdlst(token);
	set_node_number(parser);
	return (parser);
}
