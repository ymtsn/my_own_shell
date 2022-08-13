#include "mysh_def.h"
#include <stdlib.h>
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
