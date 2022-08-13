#ifndef MYSH_LEXER_H
# define MYSH_LEXER_H
t_token	*lexer(char	*src);
void	init_lexer(t_lexer *lexer, char **src);
void	change_word_to_token(t_lexer *lexer, t_token **token);
void	set_lexer_state(t_lexer *lexer);
void	set_ionumber_len(t_lexer *lexer, int token_type);
void	set_redirecter_pipe_len(t_lexer *lexer, int token_type);
void	set_word_len(t_lexer *lexer, int token_type);
void	free_token(t_token *token);
#endif
