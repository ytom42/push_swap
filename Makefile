# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 20:08:40 by ytomiyos          #+#    #+#              #
#    Updated: 2021/10/18 22:02:54 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

LIBFT	=	./libft/libft.a

SRCS	=	main.c \
			sort.c \
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
		rm -f *.o

fclean:	clean
		make fclean -C ./libft
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
