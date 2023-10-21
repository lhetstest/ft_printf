#include "ft_printf.h"

int ft_print_c_pct(t_format f, va_list args)
{
	char c;
	int cnt;

	cnt = 0;
	if (f.specifier = 'c')
		c = va_arg(args, int);
	else
		c = '%';
	f.precision = 1;
	if (!f.minus && f.zero)
		cnt += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus && f.width - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	cnt += ft_putnchar_fd(c, 1);
	if (f.minus && f.width - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (cnt);
}

int ft_print_s(t_format f, va_list ap)
{
	char *string;
	int cnt;

	cnt = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(string) || f.precision < 0)
		f.precision = ft_strlen(string);
	if (!f.minus && f.width > f.precision && f.zero && (!f.dot || f.neg_prec))
		cnt += ft_putnchar_fd('0', 1, f.width - f.precision);
	else if (!f.minus && f.width - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	cnt += ft_putstrn_fd(string, 1, f.precision);
	if (f.minus && f.width - f.precision > 0)
		cnt += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (cnt);
}