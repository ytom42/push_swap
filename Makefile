# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 20:08:40 by ytomiyos          #+#    #+#              #
#    Updated: 2021/10/12 20:31:08 by ytomiyos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

LIBFT	=	./libft/libft.a

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

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
