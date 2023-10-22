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
		return ft_print_s(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
		cnt = ft_print_d_i_u(f, args);
	if (f.specifier == 'X' || f.specifier == 'x')
		cnt = ft_print_x(f, args);
	if (f.specifier == 'p')
		cnt = ft_print_p(f, args);
	return (cnt);
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
