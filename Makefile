# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 20:08:40 by ytomiyos          #+#    #+#              #
#    Updated: 2021/12/16 18:17:30 by ytomiyos         ###   ########.fr        #
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
			tool.c \
			operation_init_a.c \
			exec_a.c \
			operations/push.c \
			operations/swap.c \
			operations/rotate.c \
			operations/reverse_rotate.c \
			test.c 

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
		make fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
