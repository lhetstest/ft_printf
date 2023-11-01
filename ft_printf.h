/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:10:18 by yrul              #+#    #+#             */
/*   Updated: 2023/10/15 21:10:24 by yrul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

int ft_printf(const char *str, ...);

int ft_print_s(char const *str);
int ft_print_int(int n);
int ft_print_uns(unsigned int num);
int ft_print_hex(unsigned int num, bool upper_case);
int ft_print_p(void *addr);

/* Checks the str after a '%' is found and fills struct */
int ft_parse(char *str, va_list ap);

#endif
