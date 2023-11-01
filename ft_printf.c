/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:58:31 by yrul              #+#    #+#             */
/*   Updated: 2023/10/15 21:09:10 by yrul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_convert(char specifier, va_list args)
{
	if (specifier == '%')
		return (write(1, "%", 1));
	else if (specifier == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (specifier == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (specifier = 'p')
		return (ft_print_p(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_uns(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(args, ssize_t), true));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(args, ssize_t), false));
	return (0);
}

int ft_printf(const char *str, ...)
{
	int i;
	int len;
	va_list args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_convert(str[i], args);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
