NAME 				=	mosh

CC 					=	gcc
COMPILE_FLGS		=	-Wall -Werror -Wextra $(DEBUG_FLG) $(INCLUDE_FLGS)
DEBUG_FLGS			=	-g

INCLUDE_DIR			=	./include
INCLUDE_FLGS		=	-I $(INCLUDE_DIR)

LIBFT_DIR			=	./src/libft
LIBFT_NAME			=	libft.a
LIBFT_FULLNAME		=	$(LIBFT_DIR)/$(LIBFT_NAME)

OBJ_DIR 			=	./obj

MAIN_SRC			=	main.c
MAIN_DIR 			=	./src/main
MAIN_SRC_FULLNAME	=	$(addprefix ./src/main/, $(MAIN_SRC))
MAIN_OBJ			=	main.o
MAIN_OBJ_FULLNAME	=	$(addprefix ./obj/, $(MAIN_OBJ))

PROMPT_SRC			=	prompt.c
PROMPT_DIR			=	./src/prompt
PROMPT_SRC_FULLNAME	=	$(addprefix ./src/prompt/, $(PROMPT_SRC))
PROMPT_OBJ			=	prompt.o
PROMPT_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PROMPT_OBJ))

GET_INPUT_SRC			=	get_input.c get_next_line.c
GET_INPUT_DIR			=	./src/get_input
GET_INPUT_SRC_FULLNAME	=	$(addprefix ./src/get_input/, $(GET_INPUT_SRC))
GET_INPUT_OBJ			=	get_input.o get_next_line.o
GET_INPUT_OBJ_FULLNAME	=	$(addprefix ./obj/, $(GET_INPUT_OBJ))

$(infomation $(MAIN_OBJ_FULLNAME))
$(infomation $(PROMPT_OBJ_FULLNAME))
$(infomation $(GET_INPUT_OBJ_FULLNAME))

all:make-libft $(NAME)

$(NAME):$(LIBFT_FULLNAME) $(PROMPT_OBJ_FULLNAME) $(GET_INPUT_OBJ_FULLNAME) $(MAIN_OBJ_FULLNAME) $(LIBFT_FULLNAME)
	$(CC) $(COMPILE_FLGS) $(PROMPT_OBJ_FULLNAME) $(GET_INPUT_OBJ_FULLNAME) $(MAIN_OBJ_FULLNAME) $(LIBFT_FULLNAME) -o $(NAME)

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
	rm -rf $(MAIN_OBJ_FULLNAME) $(GET_INPUT_OBJ_FULLNAME) $(PROMPT_OBJ_FULLNAME)
	@make -C $(LIBFT_DIR) clean

fclean:clean
	rm -rf $(NAME)

.PHONY:make-libft clean fclean
