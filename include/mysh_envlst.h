#ifndef MYSH_ENVLST
#define MYSH_ENVLST
t_envlst	*create_envlst();
void		print_envlst(t_envlst *envlst);
void		print_char_envlst(char **envlst);
void		delete_envlst_keyval(t_envlst *envlst, char *keyval);
t_envlst	*make_envvar(int type, char *keyval);
int			add_envlst_keyval(t_envlst *envlst, char *keyval);
t_envlst	*lookup_envlst(t_envlst *envlst, char *find);
char		**convert_envlst_to_char(t_envlst *envlst);
#endif
