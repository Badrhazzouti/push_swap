# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 16:21:54 by bhazzout          #+#    #+#              #
#    Updated: 2023/01/21 00:02:42 by bhazzout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

SOURCES	=	check_utils.c test2.c ft_printf_utils.c ft_printf.c ft_printff_utils2.c my_atoi.c push_swap.c \
			split.c test.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c \
			push_swap_utils5.c push_swap_utils6.c push_swap_utils7.c

OBJECTS	= 	$(SOURCES:.c=.o)

all	:	$(NAME)

$(NAME) : $(OBJECTS)
	cc -fsanitize=address -g3 $(CFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	$(RM) $(OBJECTS)

fclean	:
	$(RM) $(NAME)

re		:	fclean all
