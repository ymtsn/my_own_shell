#ifndef MYSH_ENVLIST
#define MYSH_ENVLIST
typedef enum{
	shell_variable,
	env_variable,
	exit_code,
	head,
} e_var_type;
typedef struct s_envlist{
	char 				*keyval;
	e_var_type			variable_type;
	struct s_envlist	*prev;
	struct s_envlist	*next;
} t_envlist;
t_envlist	*create_envlist();
void		print_envlist(t_envlist *envlist);
void		print_char_envlist(char **envlist);
void		delete_envlist_keyval(t_envlist *envlist, char *keyval);
t_envlist	*make_envvar(int type, char *keyval);
int			add_envlist_keyval(t_envlist *envlist, char *keyval);
t_envlist	*lookup_envlist(t_envlist *envlist, char *find);
char		**convert_envlist_to_char(t_envlist *envlist);
#endif
