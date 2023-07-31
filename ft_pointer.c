/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:27:39 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/24 14:58:52 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

static int ft_len(uintptr_t ptr)
{
	int len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_print_ptr(char *result, int i)
{
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}

static void ft_put_ptr(char *result, uintptr_t ptr)
{
	int reminder;
	int i;

	i = 0;
	while (ptr != 0)
	{
		reminder = ptr % 16;
		if (reminder < 10)
			result[i] = reminder + '0';
		else
			result[i] = reminder - 10 + 'a';
		ptr /= 16;
		i++;
	}
	i--;
	ft_print_ptr(result, i);
}

int	ft_pointer(unsigned long long ptr)
{
	int		len;
	char	*result;

	len = 0;
	len += ft_len(ptr);
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		len += 3;
	}
	else
	{
		len += ft_putchar('0');
		len += ft_putchar('x');
		result = (char *)malloc(sizeof(char) * len + 1);
		if (!result)
		return (0);
		ft_put_ptr(result, ptr);
		free(result);
	}	
	return (len);
}
