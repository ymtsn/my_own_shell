#ifndef MOSH_LEXER_H
#define MOSH_LEXER_H
#include <stddef.h>
typedef enum{
	NONE,
	WORD,
	ASSIGNMENT_WORD,
	NAME,
	NEWLINE,
	IO_NUMBER,
	PIPE,
	LESS,		/* '<' */
	GREAT,		/* '>' */
	DLESS,		/* '<<' */
	DGREAT,		/* '>>' */
	LESSAND,	/* '<&' */
	GREATAND	/* '>&' */
}	e_token_type;
typedef struct s_token{
	e_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;
typedef struct	s_lexer{
	int		state;
	char	*src;
	size_t	current_pos;
	size_t	word_start_pos;
}	t_lexer;
t_token *lexer(char	*);
void	change_word_to_token(t_lexer *lexer, t_token **token);
void	print_token(t_token *token);
#endif
