#include "mysh_envlist.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	get_totalsize(t_envlist *envlist)
{
	size_t	count;

	count = 0;
	while (envlist != NULL)
	{
		if (envlist->variable_type == env_variable)
			count++;
		envlist = envlist->next;
	}
	return (count);
}

char	**convert_envlist_to_char(t_envlist *envlist)
{
	size_t	total_list;
	char	**rtn;
	char	**save;

	total_list = 0;
	total_list = get_totalsize(envlist);
	rtn = malloc(sizeof(char **) * (total_list + 1));
	if (rtn == NULL)
	{
		perror("malloc fail at convert_envrist_to_char");
		exit(1);
	}
	save = rtn;
	while (envlist != NULL)
	{
		if (envlist->variable_type == env_variable)
		{
			*rtn = envlist->keyval;
			rtn++;
		}
		envlist = envlist->next;
	}
	rtn = NULL;
	return (save);
}
