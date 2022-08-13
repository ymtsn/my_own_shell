#ifndef MYSH_DEF
#define MYSH_DEF
#define LEXER_INIT 0
#define WHITE_SPACE 1
#define READ_WORD 2
#define STRING_END 3
#define IO_NUM_POSSIBLE 4
#define ERROR 5
#define NOT_PARSE 0
#define PARSE_DONE 1
#define DO_PREFIX 0
#define DO_SUFFIX 1
#define SUCCESS 1
#define FAIL 0
#define READ_END 0
#define WRITE_END 1
#define TRUNC_FILE	0
#define APPEND_FILE	1
#include <stddef.h>
typedef enum{
	shell_variable,
	env_variable,
	exit_code,
	head,
} e_var_type;
typedef struct s_envlst{
	char 				*keyval;
	e_var_type			variable_type;
	struct s_envlst	*prev;
	struct s_envlst	*next;
} t_envlst;
typedef enum{
	DLESS,		/* '<<' */
	DGREAT,		/* '>>' */
	DGREATAND,	/* '>>&' */
	ANDGREAT,	/* '&>' */
	LESSAND,	/* '<&' */
	GREATAND,	/* '>&' */
	LESS,		/* '<' */
	GREAT,		/* '>' */
	ASSIGNMENT_WORD,	/* '=' */
	NEWLINE,	/* '\n' */
	PIPE,		/* '|' */
	IO_NUMBER_TOKEN,
	WORD_TOKEN,
	NAME,
	NONE
}	e_token_type;
typedef struct s_token{
	e_token_type	type;
	int				parse_done_flg;
	char			*value;
	struct s_token	*next;
}	t_token;
typedef struct	s_lexer{
	e_token_type	token_type;
	int		state;
	char	*src;
	char	token_table[14][10];
	size_t	current_pos;
	size_t	word_start_pos;
}	t_lexer;
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
#endif
