#ifndef MYSH_LEXER_H
#define MYSH_LEXER_H
#include <stddef.h>
#define LEXER_INIT 0
#define WHITE_SPACE 1
#define READ_WORD 2
#define STRING_END 3
#define IO_NUM_POSSIBLE 4
#define ERROR 5
#define NOT_PARSE 0
#define PARSE_DONE 1
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
t_token *lexer(char	*);
void	init_lexer(t_lexer *, char **);
void	change_word_to_token(t_lexer *, t_token **);
void	set_lexer_state(t_lexer *);
void	free_token(t_token *token);
#endif
