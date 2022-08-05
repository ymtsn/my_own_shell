#ifndef MYSH_DEBUG_H
#define MYSH_DEBUG_H
void	print_cmdlst(t_cmdlst *cmdlst);
void	print_token(t_token *token);
int		check_debug_mode(t_cmdlst *cmdlst);
void	debug_print(t_token *token, t_cmdlst *cmdlst);
#endif
