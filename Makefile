# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 20:08:40 by ytomiyos          #+#    #+#              #
#    Updated: 2021/12/22 15:01:10 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3

NAME	=	push_swap

LIBFT	=	./libft/libft.a

SRCS	=	main.c \
			init.c \
			sort.c \
			error.c \
			tool1.c \
			tool2.c \
			operation_init.c \
			five_or_less.c \
			exec.c \
			operations/push.c \
			operations/swap.c \
			operations/rotate.c \
			operations/reverse_rotate.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
			make -C ./libft

clean:
		make clean -C ./libft
		rm -f $(OBJS)

fclean:	clean
		rm -f $(LIBFT)
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
