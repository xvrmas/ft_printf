/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:50:39 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/07/19 14:27:35 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef	LIBFPRINTF_H
# define LIBFPRINTF_H

int     ft_digit(int num);
int     ft_hex(unsigned long hex, int letter);
int     ft_pointer(void *ptr);
int     ft_printf(char const *format, ...);
int     ft_putchar(char c);
int     ft_string(char *str);

#endif
