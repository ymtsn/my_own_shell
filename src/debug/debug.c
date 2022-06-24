#include "mosh_lexer.h"
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
	(void)ft_strlcpy(table[ARG_WORD], "ARG_WORD\t", 15);
	(void)ft_strlcpy(table[IO_REDIRECT], "IO_REDIRECT", 15);
	(void)ft_strlcpy(table[IO_FILE], "IO_FILE", 15);
	(void)ft_strlcpy(table[FILENAME], "FILENAME", 15);
	(void)ft_strlcpy(table[IO_HERE], "IO_HERE", 15);
	(void)ft_strlcpy(table[HERE_END], "HERE_END", 15);
}

static void	init_token_type_table(char table[14][10])
{
	(void)ft_strlcpy(table[DLESS], "<<",3);
	(void)ft_strlcpy(table[DGREAT], ">>",3);
	(void)ft_strlcpy(table[DGREATAND], ">>&", 4);
	(void)ft_strlcpy(table[LESSAND], "<&",3);
	(void)ft_strlcpy(table[GREATAND], ">&",3);
	(void)ft_strlcpy(table[ANDGREAT], "&>", 3);
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

void	traverse_child(t_cmdlst *pnode, char node[10][15], char token[14][10])
{
	int	node_type;
	while (pnode != NULL)
	{
		node_type = pnode->node_type;
		if (node_type != CMD_PREFIX && node_type != CMD_WORD && node_type != CMD_SUFFIX)
			printf(" ");
		printf("node_type: %s\t", node[pnode->node_type]);
		printf("value: %s\t", pnode->value);
		printf("token_type: %s\n", token[pnode->token_type]);
		pnode = pnode->child;
	}
}

void	traverse_sibling(t_cmdlst *pnode, char node[10][15], char token[14][10])
{
	int	type;

	while (pnode != NULL)
	{
		type = pnode->node_type;
		if (type == CMD_PREFIX || type == CMD_WORD || type == CMD_SUFFIX)
			traverse_child(pnode, node, token);
		else
			traverse_sibling(pnode->child, node, token);
		pnode = pnode->sibling;
	}
}

void	print_cmdlst(t_cmdlst *pnode)
{
	char	node[11][15];
	char	token[14][10];

	init_node_type_table(node);
	init_token_type_table(token);
	traverse_sibling(pnode, node, token);
}
