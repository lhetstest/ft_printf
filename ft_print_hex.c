#include "ft_printf.h"

static char *ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
	int cnt;
	int remainder;
	char character;

	cnt = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HEXALOW[remainder];
		else
			character = HEXAUP[remainder];
		n /= 16;
		iteration = 1;
		cnt += ft_recursive_hex(f, n, iteration);
		cnt += ft_putchar_fd(character, 1);
	}
	return (cnt);
}

int ft_print_x(t_format f, va_list args)
{
	int cnt;
	unsigned int n;
	int len;

	cnt = 0;
	n = va_arg(args, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	cnt += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		cnt += ft_putnchar_fd('0', 1, (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		cnt += ft_putnchar_fd(' ', 1, (f.width - f.precision));
	cnt += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.zero && n));
	cnt += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		cnt += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (cnt);
}

int ft_print_p(t_format f, va_list args)
{
	int cnt;
	size_t n;
	int len;

	cnt = 0;
	n = va_arg(args, size_t);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	cnt += write(1, "0x", 2 * f.zero);
	f.width -= 2;
	if (!f.minus && f.width > f.precision && !f.dot && f.zero)
		cnt += ft_putnchar_fd('0', 1, (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		cnt += ft_putnchar_fd(' ', 1, (f.width - f.precision));
	cnt += write(1, "0x", 2 * !f.zero);
	cnt += ft_putnchar_fd('0', 1, (f.precision - len) * (n != 0));
	cnt += ft_putnchar_fd('0', 1, f.precision * (f.dot && !n));
	if (len)
		cnt += ft_recursive_hex(f, n, n);
	if (f.minus && f.width > f.precision)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (cnt);
}