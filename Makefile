# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamas-ga <xamas-ga@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 17:41:43 by xamas-ga          #+#    #+#              #
#    Updated: 2023/08/03 17:42:00 by xamas-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_digit.c ft_hex.c ft_pointer.c ft_printf.c \
	ft_putchar.c ft_string.c ft_unsign.c

OBJECTS = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I ./

${NAME}: ${OBJECTS}
	ar -rc ${NAME} ${OBJECTS}

all: ${NAME}

%.o : %.c ft_printf.h
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

fclean: clean
	rm -f  ${NAME}

clean: 
	rm -f *.o libftprintf.a

re: fclean all

.PHONY: clean fclean re
