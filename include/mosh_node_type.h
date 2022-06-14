#ifndef MOSH_NODE_TYPE_H
#define MOSH_NODE_TYPE_H
typedef enum{
	pipe_sequence,
	linebreak,
	command,
	simple_command,
	cmd_prefix,
	cmd_word,
	cmd_suffix,
	io_redirect,
	redirect_list,
	io_file,
	filename,
	io_here,
	here_end
} Node_Type
#endif
