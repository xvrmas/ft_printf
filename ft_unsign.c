/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:27 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:38:53 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

static int	ft_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static int	ft_else(unsigned int num, int i)
{
	char	str[29];
	int		err;

	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	i--;
	while (i >= 0)
	{
		err = ft_putchar(str[i]);
		if (err == -1)
			return (-1);
		i--;
	}
	if (err == -1)
		return (-1);
	return (err);
}

static int	ft_print_unsign(unsigned int num)
{
	int		i;
	int		err;

	i = 0;
	err = 0;
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	err = ft_else(num, i);
	if (err == -1)
		return (-1);
	return (err);
}

int	ft_unsign(unsigned int nb)
{
	int		len;
	int		err;

	err = 0;
	len = ft_len(nb);
	err = ft_print_unsign(nb);
	if (err == -1)
		return (-1);
	if (nb == 0)
		len = 1;
	return (len);
}
