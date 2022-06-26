#include "mosh_prompt.h"
#include "mosh_get_input.h"
#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "mosh_debug.h"
#include "mosh_executer.h"
#include "mosh_pipe.h"
#include "libft.h"
#include <stdio.h>

static void	commandline_loop(void){
	char		*src = "seq 10 | sort -r";
	t_token		*token;
	t_cmdlst	*cmd_tree;

	while (1)
	{
	/* 	prompt();
		src = get_input(); */
		if (src != NULL)
		{
			token = lexer(src);
			free(src);
			cmd_tree = parser(&token);
		/* 	print_cmdlst(cmd_tree); */
			do_pipe(cmd_tree);
			/* simple_command_execute(cmd_tree); */
			return ;
		}
	}
}

int	main(void){
	commandline_loop();
	return (0);
}
