CC = cc
DIR_INCLUDE = ./include
CFLAGS = -Wall -Wextra -Werror -I $(DIR_INCLUDE)
LIBFT = ./libft/libft.a
NAME = a.out

SRCS =	./src/main.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)
$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
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