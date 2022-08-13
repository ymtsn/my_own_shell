#include <mysh_def.h>
#include "mysh_envlst.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
int	add_envlst_keyval(t_envlst *envlst, char *keyval)
{
	if (envlst == NULL || keyval == NULL)
		return (FAIL);
	if (lookup_envlst(envlst, keyval) != NULL)
		return (FAIL);
	while (envlst->next != NULL)
		envlst = envlst->next;
	envlst->next = make_envvar(env_variable, keyval);
	envlst->next->prev = envlst;
	return (SUCCESS);
}
