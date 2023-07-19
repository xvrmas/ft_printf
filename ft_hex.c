/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:21 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/19 14:11:27 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	ft_len(int num)
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

int	ft_hex(unsigned long hex, int letter)
{
	int		i;
	int		reminder;
	int		upper;
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
	ft_puthex(result, i);
	return (i);
}
