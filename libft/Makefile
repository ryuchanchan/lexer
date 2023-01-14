# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 00:06:06 by rykawamu          #+#    #+#              #
#    Updated: 2022/06/05 21:16:03 by rykawamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c
BONUS	= ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c  ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(BONUS:.c=.o)
RM		= rm -f

all: $(NAME)
$(NAME): $(OBJS) $(B_OBJS)
	ar rs $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
re: fclean all

bonus: $(NAME)

fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJS) $(B_OBJS)

.PHONY: all clean fclean re bonus
