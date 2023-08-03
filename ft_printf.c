/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:59:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:30:26 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_format(va_list args, const char *format)
{
	int		len;
	int		result;

	len = 0;
	result = 0;
	format++;
	if (*format == 's')
		result = ft_string(va_arg(args, char *));
	else if (*format == 'x' || *format == 'X')
		result = ft_hex(va_arg(args, unsigned int), *format);
	else if (*format == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (*format == '%')
		result = ft_putchar('%');
	else if (*format == 'p')
		result = ft_pointer(va_arg(args, unsigned long));
	else if (*format == 'd' || *format == 'i')
		result = ft_digit(va_arg(args, int));
	else if (*format == 'u')
		result = ft_unsign(va_arg(args, unsigned int));
	if (result == -1)
		return (-1);
	else
		len += result;
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		result;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			result = ft_format(args, format++);
			len += result;
		}
		else
		{
			result = ft_putchar(*format);
			len += result;
		}
		if (result == -1)
			return (-1);
		format++;
	}
	va_end(args);
	return (len);
}
