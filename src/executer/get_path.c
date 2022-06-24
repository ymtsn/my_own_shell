#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "mosh_executer.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_path(t_cmdlst *cmd_tree)
{
	char	*find;
	char	*rtn;
	char	*path;
	char	**pathlist;

	find = get_node_value(cmd_tree, CMD_WORD);
	find = ft_strjoin("/", find);
	path = getenv("PATH");
	pathlist = ft_split(path, ':');
	while(*pathlist != NULL)
	{
		rtn = ft_strjoin(*pathlist, find);
		if (access(rtn, F_OK | X_OK) != -1)
			return (rtn);
		free(rtn);
		(void)*pathlist++;
	}
	return (NULL);
}
