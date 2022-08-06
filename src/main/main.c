#include "mysh_prompt.h"
#include "mysh_get_input.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_utils.h"
#include "mysh_executer.h"
#include "mysh_pipe.h"
#include "mysh_redirect.h"
#include "libft.h"
#include <stdio.h>

static void	free_variables(char * src, t_token *tkn, t_cmdlst *cmd)
{
	free(src);
	free_token(tkn);
	free_cmdlst(cmd);
}

static void cmdline_loop(void)
{
	char		*src;
	t_token		*token;
	t_cmdlst	*cmdlst;

	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			token = lexer(src);
			cmdlst = parser(token);
			if (check_debug_mode(cmdlst))
				debug_print(token, cmdlst);
			else
 				executer(cmdlst);
			free_variables(src, token, cmdlst);
		}
	}
}

int	main(void)
{
	cmdline_loop();
	return (0);
}
