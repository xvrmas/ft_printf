/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:27:39 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 19:53:03 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"

static int	ft_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static int	ft_print_ptr(char *result, int i)
{	
	int err;

	err = 0;
	while (i >= 0)
	{
		err = ft_putchar(result[i]);
		if (err == -1)
		{
			free(result);
			return(-1);
		}
		i--;
	}
	free(result);
	return (1);
}

static int	ft_put_ptr(char *result, uintptr_t ptr)
{
	int	reminder;
	int	i;
	int err;

	i = 0;
	err = 0;
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
	err = ft_print_ptr(result, i);
	if (err == -1)
		return (-1);
	return (err);
}

int	ft_pointer(unsigned long ptr)
{
	int		error;
	int		len;
	char	*result;

	len = 0;
	error = 0;
	len += ft_len(ptr);
	if (ptr == 0 || !ptr)
	{
		error =  ft_string("0x0");
		if (error == -1)
			return (-1);
		return (error);
	}
	else
	{
		len += 2;
	   	error = ft_string("0x");
		if (error == -1)
			return (-1);
		result = (char *)malloc(sizeof(char) * len + 1);
		if (!result)
		{
			free(result);
			return (-1);
		}
		error = ft_put_ptr(result, ptr);
		if (error == -1)
		{
			free(result);
			return (-1);
		}
	}
	return (len);
}
