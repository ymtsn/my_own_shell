#include "mysh_envlst.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_executer.h"
#include "mysh_utils.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**get_argv(t_cmdlst *cmdlst)
{
	size_t		node_count;
	size_t		i;
	char		**argv;

	node_count = get_node_count(cmdlst, ARG_WORD);
	argv = malloc(sizeof(char**)*(node_count + 1));
	if (argv == NULL)
	{
		perror("malloc fail at get_argv");
		exit(EXIT_FAILURE);
	}
	argv[0] = get_node_value(cmdlst, CMD_WORD);
	i = 1;
	while (cmdlst != NULL)
	{
		cmdlst = get_node_iterate(cmdlst->node_num, cmdlst, ARG_WORD);
		if (cmdlst != NULL)
		{
			argv[i] = cmdlst->value;
			i++;
		}
	}
	argv[i] = NULL;
	return (argv);
}
