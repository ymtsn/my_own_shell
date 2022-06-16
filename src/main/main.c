#include "mosh_prompt.h"
#include "mosh_get_input.h"
#include "mosh_lexer.h"
#include "libft.h"

static void	commandline_loop(void){
	char	*src;
	t_token	*token;

	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			token = lexer(src);
			free(src);
		}
	}
}

int	main(void){
	commandline_loop();
	return (0);
}
