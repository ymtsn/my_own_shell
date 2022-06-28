#include "mysh_prompt.h"
#include "mysh_get_input.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_debug.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "mysh_redirect.h"
#include "libft.h"
#include <stdio.h>

static void	commandline_loop(void){
	char		*src = "ls foo > test 2>&1";
	t_token		*token;
	t_cmdlst	*cmd_tree;

	while (1)
	{
	/* 	prompt();
		src = get_input(); */
		if (src != NULL)
		{
			token = lexer(src);
			/* free(src); */
			cmd_tree = parser(&token);
			/* print_cmdlst(cmd_tree); */
			do_redirect(cmd_tree);
		/* 	do_pipe(cmd_tree); */
			simple_command_execute(cmd_tree);
			return ;
		}
	}
}

int	main(void){
	commandline_loop();
	return (0);
}
