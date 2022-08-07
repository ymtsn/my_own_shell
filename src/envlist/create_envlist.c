#include "mysh_envlist.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

t_envlist	*make_envvar(int type, char *keyval)
{
	t_envlist	*new;

	new = malloc(sizeof(t_envlist));
	if (new == NULL)
	{
		perror("malloc fail at make_env");
		exit(1);
	}
	new->prev = NULL;
	new->next = NULL;
	new->variable_type = type;
	if (keyval == NULL)
		return (new);
	new->keyval = ft_strdup((const char*)keyval);
	if (new->keyval == NULL)
	{
		perror("ft_strdup fail at make_env");
		exit(1);
	}
	return (new);
}

t_envlist	*create_envlist()
{
	t_envlist	*envlist;
	t_envlist	*save;

	if (environ == NULL)
		return (NULL);
	envlist = make_envvar(head, NULL);
	save = envlist;
	while (*environ != NULL)
	{
		envlist->next = make_envvar(env_variable, *environ);
		envlist->next->prev = envlist;
		envlist = envlist->next;
		environ++;
	}
	return (save);
}
