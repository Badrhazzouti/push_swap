# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 16:21:54 by bhazzout          #+#    #+#              #
#    Updated: 2022/12/30 16:44:50 by bhazzout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

SOURCES	=	check_utils.c check.c ft_printf_utils.c ft_printf.c ft_printff_utils2.c my_atoi.c push_swap.c split.c test.c

OBJECTS	= 	$(SOURCES:.c=.o)

all	:	$(NAME)

$(NAME) : $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	$(RM) $(OBJECTS)

fclean	:
	$(RM) $(NAME)

re		:	fclean all
