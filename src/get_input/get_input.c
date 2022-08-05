
#include <stdlib.h>
#include "get_next_line.h"

char	*get_input()
{
	char	*src;

	src = get_next_line(1);
	while (src == NULL)
		src = get_next_line(1);
	if (src[0] == '\n')
	{
		free(src);
		return (NULL);
	}
	return (src);
}
