#include "mysh_envlst.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	get_totalsize(t_envlst *envlst)
{
	size_t	count;

	count = 0;
	while (envlst != NULL)
	{
		if (envlst->variable_type == env_variable)
			count++;
		envlst = envlst->next;
	}
	return (count);
}

char	**convert_envlst_to_char(t_envlst *envlst)
{
	size_t	total_list;
	char	**rtn;
	char	**save;

	total_list = 0;
	total_list = get_totalsize(envlst);
	rtn = malloc(sizeof(char **) * (total_list + 1));
	if (rtn == NULL)
	{
		perror("malloc fail at convert_envrist_to_char");
		exit(EXIT_FAILURE);
	}
	save = rtn;
	while (envlst != NULL)
	{
		if (envlst->variable_type == env_variable)
		{
			*rtn = envlst->keyval;
			rtn++;
		}
		envlst = envlst->next;
	}
	rtn = NULL;
	return (save);
}
