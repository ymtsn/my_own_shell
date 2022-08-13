#include "mysh_def.h"
#include "mysh_envlst.h"
#include "mysh_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_path(t_envlst *envlst, t_cmdlst *cmdlst)
{
	char	*path;
	char	*find;
	char	*rtn;
	char	**pathlist;

	find = get_node_value(cmdlst, CMD_WORD);
	if (find == NULL)
		return (NULL);
	path = ft_strjoin("/", find);
	if (path == NULL)
		return (NULL);
	envlst = lookup_envlst(envlst, "PATH");
	if (envlst == NULL)
		return (NULL);
	pathlist = ft_split(envlst->keyval + 5, ':');
	while (*pathlist != NULL)
	{
		rtn = ft_strjoin(*pathlist, path);
		if (access(rtn, F_OK | X_OK) != -1)
			return (rtn);
		free(rtn);
		pathlist++;
	}
	return (NULL);
}
