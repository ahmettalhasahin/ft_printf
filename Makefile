# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asahin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 16:18:14 by asahin            #+#    #+#              #
#    Updated: 2022/02/12 12:16:34 by asahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

OBJ	= $(SRC:.c=.o)

all	: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
