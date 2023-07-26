/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xavier <xamas-ga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:17:05 by xavier            #+#    #+#             */
/*   Updated: 2023/07/26 17:17:30 by xavier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int      ft_len(unsigned int num)
{
        int     len;

        len = 0;
        while (num != 0)
        {
                num = num / 10;
                len++;
        }
        return (len);
}

static void     ft_print_unsign(unsigned int num)
{
        int             len;
        int             i;
        char    *buffer;

        len = ft_len(num);
        i = 0;
        buffer = (char *)malloc(sizeof(char) * len);
        if (num == 0)
                ft_putchar('0');
        while (num != 0)
        {
                buffer[i] = (num % 10) + '0';
                i++;
                num /= 10;
        }
        while (i >= 0)
        {
                ft_putchar(buffer[i]);
                i--;
        }
        free(buffer);
}

int     ft_unsign(unsigned int nb)
{
        int     i;

        i = 0;
        ft_print_unsign(nb);
        while (nb != 0)
        {
                nb = nb / 10;
                i++;
        }
        return (i);
}
