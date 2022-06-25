#include "mosh_lexer.h"
#include "mosh_parser.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	init_node_type_table(char table[14][16])
{
	(void)ft_strlcpy(table[PIPELINE], "PIPELINE", 16);
	(void)ft_strlcpy(table[SIMPLE_COMMAND], "SIMPLE_COMMAND", 16);
	(void)ft_strlcpy(table[CMD_PREFIX], "CMD_PREFIX", 16);
	(void)ft_strlcpy(table[CMD_PREFIX_HEAD], "CMD_PREFIX_HEAD", 16);
	(void)ft_strlcpy(table[CMD_SUFFIX], "CMD_SUFFIX", 16);
	(void)ft_strlcpy(table[CMD_SUFFIX_HRAD], "CMD_SUFFIX_HEAD", 16);
	(void)ft_strlcpy(table[CMD_WORD], "CMD_WORD", 16);
	(void)ft_strlcpy(table[CMD_WORD_HEAD], "CMD_WORD_HEAD", 16);
	(void)ft_strlcpy(table[ARG_WORD], "ARG_WORD\t", 16);
	(void)ft_strlcpy(table[IO_REDIRECT], "IO_REDIRECT", 16);
	(void)ft_strlcpy(table[IO_FILE], "IO_FILE", 16);
	(void)ft_strlcpy(table[FILENAME], "FILENAME", 16);
	(void)ft_strlcpy(table[IO_HERE], "IO_HERE", 16);
	(void)ft_strlcpy(table[HERE_END], "HERE_END", 16);
}

static void	init_token_type_table(char table[15][10])
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

void	get_childnode(t_cmdlst *cmdlst, char node[14][16], char token[15][10])
{
	if (cmdlst == NULL)
		return;
	printf("node_type: %s\t", node[cmdlst->node_type]);
	printf("value: %s\t", cmdlst->value);
	printf("token_type: %s\t", token[cmdlst->token_type]);
	printf("node_number: %zu\n", cmdlst->node_num);
	get_childnode(cmdlst->child, node, token);
	if (cmdlst->sibling != NULL)
		get_childnode(cmdlst->sibling, node, token);
}

void	print_cmdlst(t_cmdlst *cmdlst)
{
	char	node[14][16];
	char	token[15][10];

	init_node_type_table(node);
	init_token_type_table(token);
	get_childnode(cmdlst, node, token);
}
