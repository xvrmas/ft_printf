/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamas-ga <xamas-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:48:18 by xamas-ga          #+#    #+#             */
/*   Updated: 2023/08/03 17:41:03 by xamas-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_digit(int num);
int	ft_hex(unsigned int hex, int letter);
int	ft_pointer(unsigned long ptr);
int	ft_printf(char const *format, ...);
int	ft_putchar(char c);
int	ft_string(char *str);
int	ft_unsign(unsigned int nb);
int	main(int argc, char *argv[]);
#endif
