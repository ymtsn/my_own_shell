#ifndef MYSH_LEXER_H
#define MYSH_LEXER_H
t_token *lexer(char	*);
void	init_lexer(t_lexer *, char **);
void	change_word_to_token(t_lexer *, t_token **);
void	set_lexer_state(t_lexer *);
void	free_token(t_token *token);
#endif
