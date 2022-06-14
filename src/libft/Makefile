NAME 			:= libft.a
CC 				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror

INCLUDE_DIR		:=	../../include
INCLUDE_FLGS	:=	-I $(INCLUDE_DIR)

SRCS := ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memmove.c\
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c\
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_putnbr_long_fd.c \
		ft_fstrjoin.c \
		ft_atoi_skip.c \
		ft_atos.c \
		ft_atos_skip.c
OBJDIR = ../../obj/libft
LIBFTOBJS := $(SRCS:.c=.o)
LIBFTOBJS_FULLNAME := $(addprefix ../../obj/libft/, $(LIBFTOBJS))

all:$(NAME)
$(NAME):$(LIBFTOBJS_FULLNAME)
	ar -rc $(NAME) $(LIBFTOBJS_FULLNAME)
$(OBJDIR)/%.o:%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE_FLGS) -o $@ -c $<
clean:
	rm -rf $(LIBFTOBJS_FULLNAME)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re
