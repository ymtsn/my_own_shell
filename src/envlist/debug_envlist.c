#include "libft.h"
#include "mysh_envlist.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_utils.h"
#include <stdio.h>

void	print_envlist(t_envlist *envlist)
{
	if (envlist == NULL)
		return ;
	while (envlist != NULL)
	{
		printf("%s\n", envlist->keyval);
		envlist = envlist->next;
	}
}

void	print_char_envlist(char **envlist)
{
	if (envlist == NULL)
		return ;
	while (*envlist != NULL)
	{
		printf("%s\n", *envlist);
		envlist++;
	}
	printf("%s\n", *envlist);
}
