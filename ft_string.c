/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:09:46 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/01 18:17:36 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

int	ft_string(char *str)
{
	int	i;
	int err;

	err = 0;
	i = 0;
    if (!str)
    {
        if (write(1, "(null)", 6) == -1)
	   	{
            return (-1);
        }
        return (6);
    }
	while (str[i] != '\0')
	{
		err = ft_putchar(str[i]);
		if (err == -1)
			return (-1);
		i++;
	}
	return (i);
}
