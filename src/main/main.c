#include "mysh_def.h"
#include "mysh_envlst.h"
#include "mysh_prompt.h"
#include "mysh_get_input.h"
#include "mysh_lexer.h"
#include "mysh_parser.h"
#include "mysh_utils.h"
#include "mysh_executer.h"
#include "libft.h"
#include <stdio.h>

static void	free_variables(char *src, t_token *tkn, t_cmdlst *cmd)
{
	free(src);
	free_token(tkn);
	free_cmdlst(cmd);
}

static void	cmdline_loop(void)
{
	t_envlst	*envlst;
	char		*src;
	t_token		*tokenlst;
	t_cmdlst	*cmdlst;

	envlst = create_envlst();
	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			tokenlst = lexer(src);
			cmdlst = parser(tokenlst);
			if (check_debug_mode(cmdlst))
				debug_print(tokenlst, cmdlst);
			else
				executer(envlst, cmdlst);
			free_variables(src, tokenlst, cmdlst);
		}
	}
}

int	main(void)
{
	cmdline_loop();
	return (0);
}
