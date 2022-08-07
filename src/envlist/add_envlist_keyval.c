#include "mysh_envlist.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#define SUCCESS 1
#define FAIL 0

int	add_envlist_keyval(t_envlist *envlist, char *keyval)
{
	if (envlist == NULL || keyval == NULL)
		return (FAIL);
	if (lookup_envlist(envlist, keyval) != NULL)
		return (FAIL);
	while (envlist->next != NULL)
		envlist = envlist->next;
	envlist->next = make_envvar(env_variable, keyval);
	envlist->next->prev = envlist;
	return (SUCCESS);
}
