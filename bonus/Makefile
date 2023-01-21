# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 00:12:15 by bhazzout          #+#    #+#              #
#    Updated: 2023/01/21 02:06:33 by bhazzout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	push_swap_bonus

CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -rf

SOURCES	=	checker_bonus.c bonus_utils.c bonus_utils1.c my_atoi_bonus.c split_bonus.c bonus_utils2.c get_nex_line_bonus.c \
			get_next_line_utils_bonus.c bonus_utils_instructions.c bonus_utils_instructions2.c bonus_utils_instructions3.c bonus_utils3.c

OBJECTS	= 	$(SOURCES:.c=.o)

all	:	$(NAME)

$(NAME) : $(OBJECTS)
	cc -fsanitize=address -g3 $(CFLAGS) $(OBJECTS) -o $(NAME)

clean	:
	$(RM) $(OBJECTS)

fclean	:
	$(RM) $(NAME)

re		:	fclean all