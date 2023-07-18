/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:19 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/18 19:49:53 by xavier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static int ft_len(int num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static int	ft_hex(unsigned long  hex, int letter)
{
	int		len;
	int		i;
	int		reminder;
	int 	upper;
	char	result[ft_len(hex)];

	i = 0;
	len = 0; 
	upper = 97;
	if (letter == 88)
		upper = 65;
	while (hex != 0)
	{
		reminder = hex % 16;
		if (reminder < 10)
			result[i] = reminder + '0';
		else
			result[i] = reminder - 10 + upper;
		hex /= 16;
		i++;
		len++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
	return (len);
}

static  int  ft_pointer(void  *ptr)
{
	size_t adress;
	int len;

	len = 0;
	adress = (size_t)ptr;
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_hex(adress, 'x');
	return (len);
}
static  char    *putnumb(int length, int sign, int n, int flag)
{
        char    *str;
        int             num;

        num = n;
        while (num / 10)
        {
                num /= 10;
                length++;
        }
        str = malloc(sizeof(char) * (length + 1));
        if (str == NULL)
                return (NULL);
        str[length--] = '\0';
        if (sign == -1)
                str[0] = '-';
        if (n == 0)
                str[length++] = '0';
        while (n != 0)
        {
                str[length--] = n % 10 + '0';
                n /= 10;
        }
        if (flag == 1)
                str[10] = '8';
        return (str);
}

char    *ft_itoa_printf(int n)
{
        int     sign;
        int     length;
        int     flag;

        sign = 1;
        length = 1;
        flag = 0;
        if (n == -2147483648)
        {
                n -= -1;
                flag = 1;
        }
        if (n < 0)
        {
                sign = -1;
                n *= -1;
                length++;
        }
        return (putnumb(length, sign, n, flag));
}

static int ft_digit(int num)
{
	char *str;
	int len;

	len = 0;
	str = ft_itoa_printf(num);
	len = ft_string(str);
	return (len);	
}
static void ft_print_i(void *punti)
{
	printf("%p\n", punti);
}

static int	ft_format(va_list args, const char *format)
{
	int len;

	len = 0;
	format++;
	if (*format == 's')
		len += ft_string(va_arg(args, char *));
	else if (*format == 'x' || *format == 'X')
	        len += ft_hex(va_arg(args, int), *format);
	else if (*format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_pointer(va_arg(args, void *));
	else if (*format =='d')
		len += ft_digit(va_arg(args, int));
	else if (*format == 'i')
		ft_print_i(va_arg(args, void *));

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

int main()
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
	len = ft_printf("hexa lowercase: %x \n", hex);
	ft_printf("hexa uppercase: %X \n", hex);
	i = printf("hexa lowercase: %x \n", hex);
	printf("len: %d\n", len);
	printf("i: %d\n", i);
	
	char a = 'H';
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
	punt = '@';
	ptr = &punt;
	pptr = &ptr;
	ppptr = &pptr;
	len = ft_printf("Puntero hexa ft_printf: %p\n", ppptr);
	i = printf("Puntero hexa printf:    %p\n", ppptr);
	printf("len: %d\n", len);
        printf("i: %d\n", i);


	int number = 772748.8;
	len = ft_printf("Digit:  %d\n", number);
	i = printf("Printf  %d\n", number);
	printf("len: %d\n", len);
        printf("i: %d\n", i);
	
/*	int num = 0x182b6;
	ft_printf("Format  %%i: %i \n", num);	
*/
	return (0);
}
