/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:21 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 17:51:03 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

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

static void	ft_puthex(const char *result, int i)
{
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

static int	ft_letter(int letter)
{
	int	upper;

	upper = 'A';
	if (letter == 'x')
		upper = 'a';
	return (upper);
}

static int	ft_result(unsigned int hex, char *result, int upper)
{
	int	reminder;
	int	i;
	int	len;

	i = 0;
	len = 0;
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
	ft_puthex(result, i);
	free(result);
	return (len);
}

int	ft_hex(unsigned int hex, int letter)
{
	int		upper;
	int		len;
	int		lenth;
	char	*result;

	lenth = 0;
	len = ft_len(hex);
	upper = ft_letter(letter);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
	{
		free(result);
		return (-1);
	}
	lenth += ft_result(hex, result, upper);
	if (hex == 0)
		lenth += ft_putchar('0');
	return (lenth);
}
