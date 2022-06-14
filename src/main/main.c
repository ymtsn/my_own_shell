#include <stdlib.h>
#include <unistd.h>
#include "mosh_prompt.h"
#include "mosh_get_input.h"
#include "libft.h"

void	do_commandline_loop(void){
	char	*src;

	while (1)
	{
		prompt();
		src = get_input();
		if (src != NULL)
		{
			write(1, src, ft_strlen(src));
			free(src);
		}
	}
}

int	main(void){
	do_commandline_loop();
	return (0);
}
