#ifndef MOSH_LEXER_H
#define MOSH_LEXER_H
#include <stddef.h>
typedef enum{
	DLESS,		/* '<<' */
	DGREAT,		/* '>>' */
	LESSAND,	/* '<&' */
	GREATAND,	/* '>&' */
	LESS,		/* '<' */
	GREAT,		/* '>' */
	ASSIGNMENT_WORD,	/* '=' */
	NEWLINE,	/* '\n' */
	PIPE,		/* '|' */
	IO_NUMBER,
	WORD,
	NAME,
	NONE
}	e_token_type;
typedef struct s_token{
	e_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;
typedef struct	s_lexer{
	e_token_type	token_type;
	int		state;
	char	*src;
	char	token_table[12][10];
	size_t	current_pos;
	size_t	word_start_pos;
}	t_lexer;
t_token *lexer(char	*);
void	init_lexer(t_lexer *, char **);
void	change_word_to_token(t_lexer *, t_token **);
void	set_lexer_state(t_lexer *);
void	print_token(t_token *, t_lexer *);
void	set_io_number(t_token *);
#endif
