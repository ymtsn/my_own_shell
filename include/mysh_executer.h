#ifndef MYSH_EXECUTER_H
#define MYSH_EXECUTER_H
char		*get_node_value(t_cmdlst *, int);
size_t		get_node_count(t_cmdlst *, int);
t_cmdlst	*get_node(t_cmdlst *, int);
t_cmdlst	*get_node_iterate(size_t, t_cmdlst *, int);
char		*get_path(t_cmdlst *);
char		**get_argv(t_cmdlst *);
void		my_execve(t_cmdlst *);
void		exec_simple_command(t_cmdlst *);
void		executer(t_cmdlst *cmdlst);
#endif
