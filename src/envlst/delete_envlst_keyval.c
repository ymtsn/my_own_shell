#include "mysh_envlst.h"
#include <stdlib.h>
#include <stdio.h>

void	delete_envlst_keyval(t_envlst *envlst, char *find)
{
	t_envlst	*target;

	if (envlst == NULL || find == NULL)
		return ;
	target = lookup_envlst(envlst, find);
	if (target == NULL)
		return ;
	if (target->prev != NULL)
		target->prev->next = target->next;
	if (target->next != NULL)
		target->next->prev = target->prev;
	free(target->keyval);
	free(target);
}
