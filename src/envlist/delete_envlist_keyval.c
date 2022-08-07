#include "mysh_envlist.h"
#include <stdlib.h>
#include <stdio.h>

void	delete_envlist_keyval(t_envlist *envlist, char *find)
{
	t_envlist	*target;

	if (envlist == NULL || find == NULL)
		return ;
	target = lookup_envlist(envlist, find);
	if (target == NULL)
		return ;
	if (target->prev != NULL)
		target->prev->next = target->next;
	if (target->next != NULL)
		target->next->prev = target->prev;
	free(target->keyval);
	free(target);
}
