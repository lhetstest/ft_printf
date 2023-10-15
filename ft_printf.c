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

typedef struct s_sc
{
	int	len;
	int	width;
}	t_sc;

int ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	t_sc	sc;
	char c;

	while (*format){
		if (*format == '%') {
			format++;
			if (*format == 'c') {
				c = va_args(args, c);
				}
			}
		};

	
	va_end(args);
}
