/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:09:27 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/02 17:58:12 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

static int	ft_print_unsign(char *str, unsigned int num)
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
	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	i--;
	while (i >= 0)
		err = ft_putchar(str[i--]);
	if (err == -1)
		return (-1);
	free(str);
	return (err);
}

int	ft_unsign(unsigned int nb)
{
	int		len;
	int		err;
	char	*str;

	err = 0;
	len = ft_len(nb);
	if (nb == 0)
		len = 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	err = ft_print_unsign(str, nb);
	if (err == -1)
		return (-1);
	return (len);
}
