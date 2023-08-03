/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:21 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:17:44 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_printf.h"

static int	ft_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

static int	ft_puthex(const char *str, int i)
{
	int	error;

	error = 0;
	while (i >= 0)
	{
		error = ft_putchar(str[i]);
		if (error == -1)
			return (-1);
		i--;
	}
	return (1);
}

static int	ft_letter(int letter)
{
	int	upper;

	upper = 'A';
	if (letter == 'x')
		upper = 'a';
	return (upper);
}

static int	ft_result(unsigned int hex, char *str, int upper)
{
	int	reminder;
	int	i;
	int	len;
	int	err;

	i = 0;
	len = 0;
	while (hex != 0)
	{
		reminder = hex % 16;
		if (reminder < 10)
			str[i] = reminder + '0';
		else
			str[i] = reminder - 10 + upper;
		hex /= 16;
		i++;
		len++;
	}
	i--;
	err = ft_puthex(str, i);
	if (err == -1)
		return (-1);
	return (len);
}

int	ft_hex(unsigned int hex, int letter)
{
	int		upper;
	int		len;
	int		length;
	char	*str;

	length = 0;
	len = ft_len(hex);
	upper = ft_letter(letter);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free(str);
		return (-1);
	}
	length += ft_result(hex, str, upper);
	if (hex == 0)
		length += ft_putchar('0');
	free(str);
	return (length);
}
