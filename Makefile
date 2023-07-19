
NAME = libftprintf.a

SRC = ft_digit.c ft_hex.c ft_pointer.c ft_printf.c \
	ft_putchar.c ft_string.c

OBJECTS = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I ./

${NAME}: ${OBJECTS}
	ar -rc ${NAME} ${OBJECTS}

all: ${NAME}

%.o : %.c libftprintf.h
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

fclean: clean
	rm -f  ${NAME}

clean: 
	rm -f *.o libftprintf.a

re: fclean all

.PHONY: clean fclean re
