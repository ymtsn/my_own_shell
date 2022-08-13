#ifndef MYSH_UTILS_H
# define MYSH_UTILS_H
void		print_cmdlst(t_cmdlst *cmdlst);
void		print_token(t_token *token);
int			check_debug_mode(t_cmdlst *cmdlst);
void		debug_print(t_token *token, t_cmdlst *cmdlst);
char		*get_node_value(t_cmdlst *cmdlst, int type);
size_t		get_node_count(t_cmdlst *cmdlst, int type);
t_cmdlst	*get_node(t_cmdlst *cmdlst, int type);
t_cmdlst	*get_node_iterate(size_t node_num, t_cmdlst *cmdlst, int type);
#endif
