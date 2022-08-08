#ifndef MYSH_EXECUTER_H
#define MYSH_EXECUTER_H
char	*get_path(t_envlst *envlst, t_cmdlst *cmdlist);
char	**get_argv(t_cmdlst *cmdlist);
void	my_execve(t_envlst *envlst, t_cmdlst *cmdlist);
void	exec_simple_command(t_envlst *envlst, t_cmdlst *cmdlist);
void	executer(t_envlst *envlst, t_cmdlst *cmdlst);
#endif
