#include "ft_printf.h"

static size_t ft_digits_uns(unsigned int n)
{
	size_t digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

void ft_put_unsigned(unsigned int num)
{
	static char digits[] = "0123456789";

	if (num > 9)
		ft_put_unsigned(num / 10);
	write(STDOUT_FILENO, &digits[num % 10], 1);
}

int ft_print_uns(unsigned int num)
{
	ft_put_unsigned(num);
	return (ft_digits_uns(num));
}
