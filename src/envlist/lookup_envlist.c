#include "mysh_envlist.h"
#include "libft.h"
#include <stdio.h>

static size_t	get_keylen(char *keyval)
{
	size_t	count;

	if (keyval == NULL)
		return (0);
	count = 0;
	while (*keyval)
	{
		if (*keyval == '=')
			return (count);
		keyval++;
		count++;
	}
	return (0);
}

t_envlist	*lookup_envlist(t_envlist *envlist, char *find)
{
	size_t	chrpos;

	if (envlist == NULL || find == NULL)
		return (NULL);
	while (envlist != NULL)
	{
		chrpos = get_keylen(envlist->keyval);
		if (envlist->keyval != NULL)
			if (!ft_strncmp(envlist->keyval, find, chrpos))
				return (envlist);
		envlist = envlist->next;
	}
	return (NULL);
}
