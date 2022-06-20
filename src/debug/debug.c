#include "mosh_parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	init_node_type_table(char table[10][15])
{
	(void)ft_strlcpy(table[PIPELINE], "PIPELINE", 15);
	(void)ft_strlcpy(table[SIMPLE_COMMAND], "SIMPLE_COMMAND", 15);
	(void)ft_strlcpy(table[CMD_PREFIX], "CMD_PREFIX", 15);
	(void)ft_strlcpy(table[CMD_SUFFIX], "CMD_SUFFIX", 15);
	(void)ft_strlcpy(table[CMD_WORD], "CMD_WORD", 15);
	(void)ft_strlcpy(table[WORD], "WORD", 15);
	(void)ft_strlcpy(table[IO_REDIRECT], "IO_REDIRECT", 15);
	(void)ft_strlcpy(table[IO_FILE], "IO_FILE", 15);
	(void)ft_strlcpy(table[FILENAME], "FILENAME", 15);
	(void)ft_strlcpy(table[IO_HERE], "IO_HERE", 15);
	(void)ft_strlcpy(table[HERE_END], "HERE_END", 15);
}

static void	init_token_type_table(char table[12][10])
{
	(void)ft_strlcpy(table[DLESS], "<<",3);
	(void)ft_strlcpy(table[DGREAT], ">>",3);
	(void)ft_strlcpy(table[LESSAND], "<&",3);
	(void)ft_strlcpy(table[GREATAND], ">&",3);
	(void)ft_strlcpy(table[ASSIGNMENT_WORD], "=\0",3);
	(void)ft_strlcpy(table[NEWLINE], "\n",2);
	(void)ft_strlcpy(table[PIPE], "|",2);
	(void)ft_strlcpy(table[LESS], "<",2);
	(void)ft_strlcpy(table[GREAT], ">",2);
	(void)ft_strlcpy(table[IO_NUMBER], "io_number",10);
	(void)ft_strlcpy(table[NAME], "name",5);
	(void)ft_strlcpy(table[WORD_TOKEN], "word",5);
	(void)ft_strlcpy(table[NONE], "none",5);
}

void	print_pnode(t_pnode *pnode)
{
	t_pnode	*sibling;
	t_pnode	*sibling_child;
	t_pnode	*sibling_child_sibling;
	char	n_table[11][15];
	char	t_table[12][10];

	init_node_type_table(n_table);
	init_token_type_table(t_table);
	sibling = pnode;
	while (sibling != NULL)
	{
		sibling_child = sibling->child;
		sibling_child_sibling = sibling_child;
		while (sibling_child_sibling != NULL)
		{
			while (sibling_child != NULL)
			{
				printf("value:\t%s\t", sibling_child->value);
				printf("node_type:\t%s\t\t", n_table[sibling_child->node_type]);
				printf("token_type:\t%s\n", t_table[sibling_child->token_type]);
				sibling_child = sibling_child->child;
			}
			sibling_child_sibling = sibling_child_sibling->sibling;
			sibling_child = sibling_child_sibling;
		}
		sibling = sibling->sibling;
	}
}
