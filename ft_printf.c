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

int ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	char *fst;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			fst = (char *)str;
			if (*(++str))
				i += ft_parse((char *)str, args);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = fst;
		}
		else
			i += ft_putchar_fd(*str, 1);
		if (*str)
			str++;
	}
	va_end(args);
	return (i);
}

int ft_print_format(t_format f, va_list args)
{
	int count;

	count = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		count = ft_print_c_pct(f, args);
	if (f.specifier == 's')
		count = ft_print_s(f, args);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		count = ft_print_d_i_u(f, args);
	if (f.specifier == 'X' || f.specifier == 'x')
		count = ft_print_x(f, args);
	if (f.specifier == 'p')
		count = ft_print_p(f, args);
	return (count);
}