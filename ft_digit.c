/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:32:37 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 17:31:51 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

static void	ft_putnb(long n)
{
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else if (n > 9)
	{
		ft_putnb(n / 10);
		ft_putnb(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

int	ft_digit(int num)
{
	long	n;
	int		i;

	n = num;
	i = 1;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (num < 0)
		num = -num;
	ft_putnb(num);
	if (num == -2147483648)
		i = 11;
	return (i);
}
