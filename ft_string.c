/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:09:46 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:36:14 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_string(char *str)
{
	int	i;

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
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
