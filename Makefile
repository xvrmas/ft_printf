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
# Definition of the output file name
NAME = libftprintf.a

# Definition of the source file
SRC = ft_printf.c ft_digit.c ft_hex.c ft_pointer.c \
	ft_putchar.c ft_string.c ft_unsign.c

# Generating object file names from source files
OBJECTS = ${SRC:.c=.o}

# Compilation flags (warnings)
CFLAGS = -Wall -Werror -Wextra

# Inclusion options (header search folders)
INCLUDE = -I ./

# Rule to build the output file
${NAME}: ${OBJECTS}
	ar -rc ${NAME} ${OBJECTS}

# Default rule that builds the output file
all: ${NAME}

# Rule to compile source files into object files
%.o : %.c ft_printf.h
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

# Rule to remove generated files and the output file
fclean: clean
	rm -f  ${NAME}

# Rule to remove object files
clean:
	rm -f *.o libftprintf.a

# Rule to rebuild everything by cleaning first
re: fclean all

# Declaration of rules that are not file names
.PHONY: clean fclean re

