NAME 				=	minishell

CC 					=	gcc
COMPILE_FLGS		=	-Wall -Werror -Wextra $(DEBUG_FLGS)
DEBUG_FLGS			=	
INCLUDE_DIR			=	./include
INCLUDE_FLGS		=	-I $(INCLUDE_DIR)
DEPEND_FLGS			=	-MMD -MP

LIBFT_DIR			=	./src/libft
LIBFT_NAME			=	libft.a
LIBFT_FULLNAME		=	$(LIBFT_DIR)/$(LIBFT_NAME)

OBJ_DIR 			=	./obj/minishell

MAIN_SRC				=	main.c
MAIN_DIR 				=	./src/main
MAIN_SRC_FULLNAME		=	$(addprefix ./src/main/, $(MAIN_SRC))
MAIN_OBJ				=	$(MAIN_SRC:.c=.o)
MAIN_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(MAIN_OBJ))

PROMPT_SRC				=	prompt.c
PROMPT_DIR				=	./src/prompt
PROMPT_SRC_FULLNAME		=	$(addprefix ./src/prompt/, $(PROMPT_SRC))
PROMPT_OBJ				=	$(PROMPT_SRC:.c=.o)
PROMPT_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(PROMPT_OBJ))

GET_INPUT_SRC			=	get_input.c get_next_line.c
GET_INPUT_DIR			=	./src/get_input
GET_INPUT_SRC_FULLNAME	=	$(addprefix ./src/get_input/, $(GET_INPUT_SRC))
GET_INPUT_OBJ			=	$(GET_INPUT_SRC:.c=.o)
GET_INPUT_OBJ_FULLNAME	=	$(addprefix ./obj/minishell/, $(GET_INPUT_OBJ))

LEXER_SRC				=	change_word_to_token.c free_token.c init_lexer.c lexer_utils.c lexer.c
LEXER_DIR				=	./src/lexer
LEXER_SRC_FULLNAME		=	$(addprefix ./src/lexer/, $(LEXER_SRC))
LEXER_OBJ				=	$(LEXER_SRC:.c=.o)
LEXER_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(LEXER_OBJ))

PARSER_SRC				=	free_cmdlst.c parser_heredoc.c parser_redirect.c parser_suffix_cmd_prefix.c  parser_utils.c parser.c
PARSER_DIR				=	./src/parser
PARSER_SRC_FULLNAME		=	$(addprefix ./src/parser/, $(PARSER_SRC))
PARSER_OBJ				=	$(PARSER_SRC:.c=.o)
PARSER_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(PARSER_OBJ))

EXECUTER_SRC			=	executer.c get_argv.c get_path.c
EXECUTER_DIR			=	./src/executer
EXECUTER_SRC_FULLNAME	=	$(addprefix ./src/executer/, $(EXECUTER_SRC))
EXECUTER_OBJ			=	$(EXECUTER_SRC:.c=.o)
EXECUTER_OBJ_FULLNAME	=	$(addprefix ./obj/minishell/, $(EXECUTER_OBJ))

PIPE_SRC				=	pipe.c
PIPE_DIR				=	./src/pipe
PIPE_SRC_FULLNAME		=	$(addprefix ./src/pipe/, $(PIPE_SRC))
PIPE_OBJ				=	$(PIPE_SRC:.c=.o)
PIPE_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(PIPE_OBJ))

REDIRECT_SRC			=	redirect.c
REDIRECT_DIR			=	./src/redirect
REDIRECT_SRC_FULLNAME	=	$(addprefix ./src/redirect/, $(REDIRECT_SRC))
REDIRECT_OBJ			=	$(REDIRECT_SRC:.c=.o)
REDIRECT_OBJ_FULLNAME	=	$(addprefix ./obj/minishell/, $(REDIRECT_OBJ))

SYMBOL_SRC				=	add_symbol_keyval.c convert_symbol_to_char.c create_symbol.c debug_symbol.c \
							delete_symbol_keyval.c lookup_symbol.c
SYMBOL_DIR				=	./src/symbol
SYMBOL_SRC_FULLNAME		=	$(addprefix ./src/symbol/, $(SYMBOL_SRC))
SYMBOL_OBJ				=	$(SYMBOL_SRC:.c=.o)
SYMBOL_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(SYMBOL_OBJ))

UTILS_SRC				=	check_debug_mode.c debug_cmdlst.c debug_token.c get_node_utils.c
UTILS_DIR				=	./src/utils
UTILS_SRC_FULLNAME		=	$(addprefix ./src/utils/, $(UTILS_SRC))
UTILS_OBJ				=	$(UTILS_SRC:.c=.o)
UTILS_OBJ_FULLNAME		=	$(addprefix ./obj/minishell/, $(UTILS_OBJ))

OBJ_FILE_LIST			=	$(MAIN_OBJ_FULLNAME) \
							$(PROMPT_OBJ_FULLNAME) \
							$(GET_INPUT_OBJ_FULLNAME) \
							$(LEXER_OBJ_FULLNAME) \
							$(PARSER_OBJ_FULLNAME) \
							$(EXECUTER_OBJ_FULLNAME) \
							$(PIPE_OBJ_FULLNAME) \
							$(REDIRECT_OBJ_FULLNAME) \
							$(SYMBOL_OBJ_FULLNAME) \
							$(UTILS_OBJ_FULLNAME)

DEPEND_FILE_LIST		=	$(OBJ_FILE_LIST:.o=.d)

all:make-libft $(NAME)

$(NAME): $(OBJ_FILE_LIST) $(LIBFT_FULLNAME)
	$(CC) $(COMPILE_FLGS) $(OBJ_FILE_LIST) $(LIBFT_FULLNAME) -o $(NAME)

$(OBJ_DIR)/%.o:$(MAIN_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $< 

$(OBJ_DIR)/%.o:$(PROMPT_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(GET_INPUT_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(LEXER_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(PARSER_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(EXECUTER_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(PIPE_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(REDIRECT_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SYMBOL_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

$(OBJ_DIR)/%.o:$(UTILS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) $(INCLUDE_FLGS) $(DEPEND_FLGS) -o $@ -c $<

make-libft:
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_FILE_LIST)
	rm -rf $(DEPEND_FILE_LIST)
	make -C $(LIBFT_DIR) fclean

fclean:clean
	rm -rf $(NAME)

re:fclean all

norm:
	norminette | grep "Error" || true

debug:
	make DEBUG_FLGS="-g -fsanitize=address -fsanitize=undefined -fsanitize=integer"

.PHONY:all make-libft clean fclean re norm debug

-include $(DEPEND_FILE_LIST)
