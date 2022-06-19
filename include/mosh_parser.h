#ifndef MOSH_PARSER_H
#define MOSH_PARSER_H
#include "mosh_lexer.h"
typedef enum {
	PIPELINE,
	SIMPLE_COMMAND,
	CMD_PREFIX,
	CMD_SUFFIX,
	CMD_WORD,
	IO_REDIRECT,
	IO_FILE,
	FILENAME,
	IO_HERE,
	HERE_END
} e_node_type;
typedef struct s_pnode{
	char			*value;
	e_node_type		node_type;
	struct s_pnode	*child;
	struct s_pnode	*sibling;
} t_pnode;
void	parser(t_token **);
t_pnode	*create_new_pnode(e_node_type);
size_t	child_listsize(t_pnode *);
void	print_pnode(t_pnode *);
#endif
