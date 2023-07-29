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
#include <stdio.h>
#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	size_t	adress;
	int		len;
	if (ptr == NULL)
		return (ft_string("(NULL)"));
	len = 0;
	adress = (size_t)ptr;
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_hex(adress, 'x');
	return (len);
}
