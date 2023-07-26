/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:59:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/26 19:25:57 by xavier           ###   ########.fr       */
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
		len += ft_hex(va_arg(args, unsigned long), *format);
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		len += ft_putchar(c);
	}
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i') 
		len += ft_digit(va_arg(args, int));
	else if (*format == 'u')
		len += ft_unsign(va_arg(args, unsigned int));
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
{*/
/*	int len;
	int i;

	int len2;
	int len3;
*/
/*	char *s1 = "La guerra de las galaxias";
	char *s2 = "George Lucas";
	char *s3 = "1974";
	len = ft_printf("String: %s, director: %s, year: %s.\n", s1, s2, s3);

	i = printf("String: %s, director: %s, year: %s.\n", s1, s2, s3);
	printf("len: %d\n", len);
	printf("i: %d\n", i);
*/
/*	int  hex = 0;
	int hex2 = 25988075;
	len = ft_printf("hexa lowercase: %x y %x \n", hex, hex2);
	len2 = ft_printf("hexa uppercase: %X y %X \n", hex, hex2);
	i =      printf("lowerca printf: %x y %x \n", hex, hex2);
	len3 =   printf("uppercase prin: %X y %X \n", hex, hex2);
	printf("len:  %d\n", len);
	printf("len2: %d\n", len2);
	printf("i:    %d\n", i);
	printf("len3: %d\n", len3);

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
    len = ft_printf("Puntero hexa ft_printf: %p y %p\n", ppptr, NULL);
    i = printf("Puntero hexa printf:    %p y %p\n", ppptr, NULL);
    printf("len: %d\n", len);
    printf("i:   %d\n", i);
*/
/*	char a = 'H';
	len = ft_printf("char: %%m%c \n", a);
	i = printf("char: %%m%c \n", a);
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	len = ft_printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	i = printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	len = ft_printf("%d",2147483647);
	ft_printf("\n");
	i = printf("%d", 2147483647);
	printf("\nlen: %d", len);
    printf("\ni: %d\n", i);
*/

/*	int j;
	int k;

	j = ft_printf("%u", -10);
	ft_printf("\n");
	k = printf("%u", -10);
	printf("\nft_print: %d\n", j);
	printf("printf: %d\n", k);
	return (0);

}*/	
