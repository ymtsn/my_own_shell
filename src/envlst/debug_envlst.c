#include "libft.h"
#include "mysh_envlst.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_utils.h"
#include <stdio.h>

void	print_envlst(t_envlst *envlst)
{
	if (envlst == NULL)
		return ;
	while (envlst != NULL)
	{
		printf("%s\n", envlst->keyval);
		envlst = envlst->next;
	}
}

void	print_char_envlst(char **envlst)
{
	if (envlst == NULL)
		return ;
	while (*envlst != NULL)
	{
		printf("%s\n", *envlst);
		envlst++;
	}
	printf("%s\n", *envlst);
}
