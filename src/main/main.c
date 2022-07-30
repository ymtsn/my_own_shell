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

static void	commandline_loop(void)
{
	t_token		*token;
	t_cmdlst	*cmdlst;
	char		*src;

	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			token = lexer(src);
			cmdlst = parser(token);
			free(src);
			free_token(token);
			free_cmdlst(cmdlst);
			return ;
		/* 	print_token(token); */
		/* 	print_cmdlst(cmdlst); */
		/* 	do_redirect(cmdlst); */
		/* 	do_pipe(cmdlst); */
		/* 	simple_command_execute(cmdlst); */
		}
	}
}

int	main(void){
	commandline_loop();
	return (0);
}
