/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:23:19 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/14 14:31:03 by xavier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

static void	ft_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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

static void	ft_hex(unsigned long  hex, int letter)
{
	int		i;
	int		reminder;
	int 	upper;
	char	result[ft_len(hex)];

	i = 0;
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
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

static void ft_pointer(void  *ptr)
{
	size_t adress;

	adress = (size_t)ptr;
	ft_putchar('0');
	ft_putchar('x');
	ft_hex(adress, 'x');
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

static void ft_digit(int num)
{
	char *str;

	str = ft_itoa_printf(num);
	ft_string(str);	
}
static void ft_print_i(void *punti)
{
	printf("%p\n", punti);
}

static void	ft_format(va_list args, const char *format)
{
	format++;
	if (*format == 's')
		ft_string(va_arg(args, char *));
	else if (*format == 'x' || *format == 'X')
		ft_hex(va_arg(args, int), *format);
	else if (*format == 'c')
		ft_putchar(va_arg(args, int));
	else if (*format == '%')
		ft_putchar('%');
	else if (*format == 'p')
		ft_pointer(va_arg(args, void *));
	else if (*format =='d')
		ft_digit(va_arg(args, int));
	else if (*format == 'i')
		ft_print_i(va_arg(args, void *));
}

int	ft_printf(char const *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_format(args, format);
			format++;
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("\n");
	ft_printf("\n");
	
	char *s1 = "La guerra de las galaxias";
	char *s5 = "George Lucas";
	ft_printf("String: %s, director: %s.\n", s1, s5);

	size_t  hex = 946;
	ft_printf("hexa lowercase: %x \n", hex);
	ft_printf("hexa uppercase: %X \n", hex);
	
	char a = 'H';
	ft_printf("char: %c \n", a);

	ft_printf("Porcentaje: 100%%, 75%% y 25%%\n");

	char punt;
	char *ptr;
	char **pptr;
	char ***ppptr;
	punt = '@';
	ptr = &punt;
	pptr = &ptr;
	ppptr = &pptr;
	ft_printf("Puntero hexa ft_printf: %p\n", ppptr);
	printf("Puntero hexa printf:    %p\n", ppptr);

	int number = 214748.8;
	ft_printf("Digit:  %d\n", number);
	printf("Printf  %d\n", number);
	
/*	int num = 0x182b6;
	ft_printf("Format  %%i: %i \n", num);	
*/
	return (0);
}
