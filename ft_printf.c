/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:59:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/20 19:06:30 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

static int	ft_format(va_list args, const char *format)
{
	int		len;
	char	c;

	len = 0;
	format++;
	if (*format == 's')
		len += ft_string(va_arg(args, char *));
	else if (*format == 'x' || *format == 'X')
		len += ft_hex(va_arg(args,  long), *format);
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		len += ft_putchar(c);
	}
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_pointer(va_arg(args, void *));
	else if (*format == 'd')
		len += ft_digit(va_arg(args, size_t));
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len += ft_format(args, format);
			format++;
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	int len;
	int i;
	int len2;
	char *s1 = "La guerra de las galaxias";
	char *s5 = "George Lucas";
	len = ft_printf("String: %s, director: %s.\n", s1, s5);

	i = printf("String: %s, director: %s.\n", s1, s5);
	printf("len: %d\n", len);
	printf("i: %d\n", i);

	int  hex = 925568;
	int hex2 = 28855;
	len = ft_printf("hexa lowercase: %x y %x \n", hex, hex2);
	len2 = ft_printf("hexa uppercase: %X y %X \n", hex, hex2);
	i =      printf("lowerca printf: %x y %x \n", hex, hex2);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	printf("i: %d\n", i);

	char a = 'A';
	len = ft_printf("char: %%%c \n", a);
	i = printf("char: %%%c \n", a);
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	len = ft_printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	i = printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	printf("len: %d\n", len);
        printf("i: %d\n", i);


	char punt;
	char *ptr;
	char **pptr;
	char ***ppptr;
	char punt2;
	char *ptr2;

	punt = '@';
	punt2 = '<';
	ptr = &punt;
	pptr = &ptr;
	ppptr = &pptr;
	ptr2 = &punt2;
	len = ft_printf("Puntero hexa ft_printf: %p y %p\n", ppptr, ptr2);
        i = printf("Puntero hexa printf:    %p y %p\n", ppptr, ptr2);
	printf("len: %d\n", len);
        printf("i: %d\n", i);


	int number = 7727488;
	len = ft_printf("Digit:  %d\n", number);
	i = printf("Printf  %d\n", number);
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	int num = 0x182b6;
	ft_printf("Format  %%i: %i \n", num);

	return (0);
}*
