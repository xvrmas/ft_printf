/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:27 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/27 13:51:21 by xamas-ga         ###   ########.fr       */
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

static void	ft_print_unsign(unsigned int num)
{
	int		len;
	int		i;
	char	*str;

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
	{
		ft_putchar(str[i]);
		i--;
	}
	free(str);
}

int	ft_unsign(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	ft_print_unsign(nb);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
