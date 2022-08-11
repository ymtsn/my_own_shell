#ifndef MYSH_PARSER_H
#define MYSH_PARSER_H
#define DO_PREFIX 0
#define DO_SUFFIX 1
typedef enum {
	PIPELINE,
	SIMPLE_COMMAND,
	CMD_PREFIX_HEAD,
	CMD_PREFIX,
	CMD_SUFFIX,
	CMD_SUFFIX_HEAD,
	CMD_WORD,
	CMD_WORD_HEAD,
	ARG_WORD,
	IO_REDIRECT,
	IO_NUMBER,
	IO_FILE,
	FILENAME,
	IO_HERE,
	HERE_END
} e_node_type;
typedef struct s_cmdlst{
	char			*value;
	size_t			node_num;
	e_token_type	token_type;
	e_node_type		node_type;
	struct s_cmdlst	*child;
	struct s_cmdlst	*sibling;
} t_cmdlst;
t_cmdlst	*parser(t_token *token);
t_cmdlst	*cmd_suffix(t_token *token);
t_cmdlst	*cmd_prefix(t_token *token);
t_cmdlst	*io_redirect(t_token *token, int suffix_flg);
t_cmdlst	*word(t_token *token);
t_cmdlst	*create_new_node(e_node_type, e_token_type);
void		set_node_number(t_cmdlst *cmdlst);
size_t		child_listsize(t_cmdlst *cmdlst);
void		free_cmdlst(t_cmdlst *cmdlst);
#endif
