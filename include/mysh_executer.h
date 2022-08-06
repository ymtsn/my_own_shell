#ifndef MYSH_EXECUTER_H
#define MYSH_EXECUTER_H
char	*get_path(t_cmdlst *);
char	**get_argv(t_cmdlst *);
void	my_execve(t_cmdlst *);
void	exec_simple_command(t_cmdlst *);
void	executer(t_cmdlst *cmdlst);
#endif
