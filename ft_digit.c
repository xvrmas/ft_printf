/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:32:37 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/19 14:12:13 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libftprintf.h"

static char	*putnumb(int length, int sign, int n, int flag)
{
	char	*str;
	int		num;

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

static char	*ft_itoa_printf(int n)
{
	int	sign;
	int	length;
	int	flag;

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

int	ft_digit(int num)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa_printf(num);
	len = ft_string(str);
	return (len);
}
