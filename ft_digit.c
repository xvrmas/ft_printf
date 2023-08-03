/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:32:37 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:12:23 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putnb(long n)
{
	int	err;

	err = 0;
	if (n == -2147483648)
	{
		err = ft_string("2147483648");
		if (err == -1)
			return (-1);
	}
	else if (n > 9)
	{
		err = ft_putnb(n / 10);
		if (err == -1)
			return (-1);
		err = ft_putnb(n % 10);
		if (err == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
	}
	return (1);
}

static int	ft_put_digit(int n, int num, int i)
{
	int	err;

	err = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (num < 0)
		num = -num;
	err = ft_putnb(num);
	if (err == -1)
		return (-1);
	if (num == -2147483648)
		i = 10;
	return (i);
}

int	ft_digit(int num)
{
	int		err;
	int		i;
	long	n;

	n = num;
	i = 1;
	err = 0;
	if (n < 0)
	{
		n = -n;
		err = ft_putchar('-');
		if (err == -1)
			return (-1);
	}
	i = ft_put_digit(n, num, i);
	if (i == -1)
		return (-1);
	else if (num < 0)
		i += 1;
	return (i);
}
