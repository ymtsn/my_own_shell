#include <stdlib.h>
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include <stdio.h>

void	free_cmdlst(t_cmdlst *cmdlst)
{
	if (cmdlst == NULL)
		return;
	if (cmdlst->sibling != NULL)
		free_cmdlst(cmdlst->sibling);
	free_cmdlst(cmdlst->child);
	free(cmdlst);
}
