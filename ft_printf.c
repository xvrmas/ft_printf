/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:59:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/19 15:00:26 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libftprintf.h"

static int	ft_format(void *args, const char *format)
{
	int len;

	len = 0;
	format++;
	if (*format == 's')
		len += ft_string((char *)args);
	else if (*format == 'x' || *format == 'X')
	        len += ft_hex((unsigned long)args, *format);
	else if (*format == 'c')
		len += ft_putchar((size_t)args);
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_pointer((void *)args);
	else if (*format =='d')
		len += ft_digit((size_t)args);
/*	else if (*format == 'i')
		ft_print_i((void *)args);
*/
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int len;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len += ft_format(va_arg(args, void *), format);
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
	char *s1 = "La guerra de las galaxias";
	char *s5 = "George Lucas";
	len = ft_printf("String: %s, director: %s.\n", s1, s5);

	i = printf("String: %s, director: %s.\n", s1, s5);
	printf("len: %d\n", len);
	printf("i: %d\n", i);

	int  hex = 877946;
	int hex2 = 255;
	len = ft_printf("hexa lowercase: %x y %x \n", hex, hex2);
	ft_printf("hexa uppercase: %X y %X \n", hex, hex2);
	i = printf("hexa lowercase: %x y %x \n", hex, hex2);
	printf("len: %d\n", len);
	printf("i: %d\n", i);

	char a = '<';
	len = ft_printf("char: %c \n", a);
	i = printf("char: %c \n", a);
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
}*/
