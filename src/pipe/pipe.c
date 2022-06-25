#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "mosh_pipe.h"

void	pipe(t_cmdlst *cmd_tree)
{
	size_t		pipe_count;
	t_cmdlst	*node;

	pipe_count = 0;
	node = cmd_tree;
	while (node! = NULL)
	{
		if (node->node_type == PIPELINE)
			pipe_count++;
		node = node->sibling;
	}
}
