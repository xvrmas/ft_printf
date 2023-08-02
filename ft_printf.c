/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:59:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 19:53:10 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
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
		len += ft_hex(va_arg(args, unsigned int), *format);
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		len += ft_putchar(c);
	}
	else if (*format == '%')
		len += ft_putchar('%');
	else if (*format == 'p')
		len += ft_pointer(va_arg(args, unsigned  long));
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
	int result;

	len = 0;
	result = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			len += ft_format(args, format);
			if (len == -1)
			{
				return (-1);
			}
			format++;
		}
		else
		{
			result = ft_putchar(*format);
		        if (result == -1)
			{
            		    return -1;
			}
           	}
            	len += result;
	}
	format++;
	va_end(args);
	return (len);
}
