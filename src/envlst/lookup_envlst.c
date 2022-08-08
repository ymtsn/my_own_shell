#include "mysh_envlst.h"
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

t_envlst	*lookup_envlst(t_envlst *envlst, char *find)
{
	size_t	chrpos;

	if (envlst == NULL || find == NULL)
		return (NULL);
	while (envlst != NULL)
	{
		chrpos = get_keylen(envlst->keyval);
		if (envlst->keyval != NULL)
			if (!ft_strncmp(envlst->keyval, find, chrpos))
				return (envlst);
		envlst = envlst->next;
	}
	return (NULL);
}
