#include "mysh_envlst.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

extern char	**environ;

t_envlst	*make_envvar(int type, char *keyval)
{
	t_envlst	*new;

	new = malloc(sizeof(t_envlst));
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

t_envlst	*create_envlst()
{
	t_envlst	*envlst;
	t_envlst	*save;

	if (environ == NULL)
		return (NULL);
	envlst = make_envvar(head, NULL);
	save = envlst;
	while (*environ != NULL)
	{
		envlst->next = make_envvar(env_variable, *environ);
		envlst->next->prev = envlst;
		envlst = envlst->next;
		environ++;
	}
	return (save);
}
