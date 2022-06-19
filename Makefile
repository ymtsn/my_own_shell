NAME 				=	mosh

CC 					=	gcc
COMPILE_FLGS		=	-Wall -Werror -Wextra $(DEBUG_FLGS) $(INCLUDE_FLGS)
DEBUG_FLGS			=	-g

INCLUDE_DIR			=	./include
INCLUDE_FLGS		=	-I $(INCLUDE_DIR)

LIBFT_DIR			=	./src/libft
LIBFT_NAME			=	libft.a
LIBFT_FULLNAME		=	$(LIBFT_DIR)/$(LIBFT_NAME)

OBJ_DIR 			=	./obj/mosh

MAIN_SRC				=	main.c
MAIN_DIR 				=	./src/main
MAIN_SRC_FULLNAME		=	$(addprefix ./src/main/, $(MAIN_SRC))
MAIN_OBJ				=	main.o
MAIN_OBJ_FULLNAME		=	$(addprefix ./obj/mosh/, $(MAIN_OBJ))

PROMPT_SRC				=	prompt.c
PROMPT_DIR				=	./src/prompt
PROMPT_SRC_FULLNAME		=	$(addprefix ./src/prompt/, $(PROMPT_SRC))
PROMPT_OBJ				=	$(PROMPT_SRC:.c=.o)
PROMPT_OBJ_FULLNAME		=	$(addprefix ./obj/mosh/, $(PROMPT_OBJ))

GET_INPUT_SRC			=	get_input.c get_next_line.c
GET_INPUT_DIR			=	./src/get_input
GET_INPUT_SRC_FULLNAME	=	$(addprefix ./src/get_input/, $(GET_INPUT_SRC))
GET_INPUT_OBJ			=	$(GET_INPUT_SRC:.c=.o)
GET_INPUT_OBJ_FULLNAME	=	$(addprefix ./obj/mosh/, $(GET_INPUT_OBJ))

LEXER_SRC				=	lexer.c init_lexer.c change_word_to_token.c set_io_number.c
LEXER_DIR				=	./src/lexer
LEXER_SRC_FULLNAME		=	$(addprefix ./src/lexer/, $(LEXER_SRC))
LEXER_OBJ				=	$(LEXER_SRC:.c=.o)
LEXER_OBJ_FULLNAME		=	$(addprefix ./obj/mosh/, $(LEXER_OBJ))

PARSER_SRC				=	parser.c parser_node.c
PARSER_DIR				=	./src/parser
PARSER_SRC_FULLNAME		=	$(addprefix ./src/parser/, $(PARSER_SRC))
PARSER_OBJ				=	$(PARSER_SRC:.c=.o)
PARSER_OBJ_FULLNAME		=	$(addprefix ./obj/mosh/, $(PARSER_OBJ))

OBJ_FILE_LIST			=	$(MAIN_OBJ_FULLNAME) \
							$(PROMPT_OBJ_FULLNAME) \
							$(GET_INPUT_OBJ_FULLNAME) \
							$(LEXER_OBJ_FULLNAME) \
							$(PARSER_OBJ_FULLNAME)

all:make-libft $(NAME)

$(NAME): $(OBJ_FILE_LIST) $(LIBFT_FULLNAME)
	$(CC) $(COMPILE_FLGS) $(OBJ_FILE_LIST) $(LIBFT_FULLNAME) -o $(NAME)

$(OBJ_DIR)/%.o:$(PARSER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(LEXER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(PROMPT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(GET_INPUT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) -c $^ -o $@

$(MAIN_OBJ_FULLNAME):$(MAIN_SRC_FULLNAME)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLGS) -c $^ -o $@

make-libft:
	@make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_FILE_LIST)
#	@make -C $(LIBFT_DIR) clean

fclean:clean
	rm -rf $(NAME)

.PHONY:make-libft clean fclean
