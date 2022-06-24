#ifndef MOSH_EXECUTER_H
#define MOSH_EXECUTER_H
void		simple_command_execute(t_cmdlst *);
char		*get_node_value(t_cmdlst *, int);
char		*get_path(t_cmdlst *);
char		**get_argv(t_cmdlst *);
size_t		get_node_count(t_cmdlst *, int);
t_cmdlst	*get_node(t_cmdlst *, int);
t_cmdlst	*get_node_iterate(t_cmdlst *, t_cmdlst *, int);
#endif
