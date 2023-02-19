CC			= cc
DIR_INCLUDE = ./include
CFLAGS		= -Wall -Wextra -Werror -I $(DIR_INCLUDE)
LIB			= -I$(shell brew --prefix readline)/include -L$(shell brew --prefix readline)/lib -lreadline
LIBFT 		= ./libft/libft.a
NAME 		= a.out
DIR_SRC 	= ./src

SRCS 		=	$(DIR_SRC)/main.c \
				$(DIR_SRC)/utils.c \
				$(DIR_SRC)/token.c \
				$(DIR_SRC)/parser.c \
				$(DIR_SRC)/heredoc.c
OBJS 		=	$(SRCS:.c=.o)

all:	$(NAME)
$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $^ -o $@
$(LIBFT):
	make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJS)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re