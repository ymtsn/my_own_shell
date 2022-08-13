#ifndef MYSH_PARSER_H
#define MYSH_PARSER_H
t_cmdlst	*parser(t_token *token);
t_cmdlst	*cmd_suffix(t_token *token);
t_cmdlst	*cmd_prefix(t_token *token);
t_cmdlst	*io_redirect(t_token *token, int suffix_flg);
t_cmdlst	*word(t_token *token);
t_cmdlst	*create_new_node(e_node_type, e_token_type);
void		set_node_number(t_cmdlst *cmdlst);
void		skip_parsed_token(t_token **token);
void		free_cmdlst(t_cmdlst *cmdlst);
#endif
