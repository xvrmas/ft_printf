/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:21 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/20 19:06:36 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_len(long num)
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

int	ft_hex(long hex, int letter)
{
	int		i;
	int		reminder;
	int		upper;
	int		len;
	char	*result;

	i = 0;
	upper = 'A';
	len = ft_len(hex);
	result = (char *)malloc(sizeof(char) * len);
	len = 0;
	if (letter == 'x')
		upper = 'a';
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
