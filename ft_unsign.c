/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:27 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 17:32:05 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static int	ft_print_unsign(unsigned int num)
{
	int		len;
	int		i;
	char	*str;
	int		err;

	len = ft_len(num);
	i = 0;
	if (num == 0)
		ft_putchar('0');
	str = (char *)malloc(sizeof(char) * len + 1);
	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	i--;
	while (i >= 0)
		err = ft_putchar(str[i--]);
	free(str);
	return (err);
}

int	ft_unsign(unsigned int nb)
{
	int	j;
	int	error;

	j = 0;
	if (nb == 0)
		j = 1;
	error = ft_print_unsign(nb);
	if (error == -1)
		return (-1);
	while (nb != 0)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}
