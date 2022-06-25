#include "mosh_prompt.h"
#include "mosh_get_input.h"
#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "mosh_debug.h"
#include "mosh_executer.h"
#include "libft.h"
#include <stdio.h>

static void	commandline_loop(void){
	char		*src = "ls -l -a | wc -l";
	t_token		*token;
	t_cmdlst	*command_tree;

	while (1)
	{
	/* 	prompt();
		src = get_input(); */
		if (src != NULL)
		{
			token = lexer(src);
			/* free(src); */
			command_tree = parser(&token);
			print_cmdlst(command_tree);
			/* simple_command_execute(command_tree); */
			return ;
		}
	}
}

int	main(void){
	commandline_loop();
	return (0);
}
