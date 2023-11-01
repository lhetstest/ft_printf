
#include "ft_printf.h"

static size_t ft_digits_int(int n)
{
	size_t digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

static void ft_put_int(int n)
{
	static char digits[] = "0123456789";

	if (n > 9)
		ft_put_int(n / 10);
	write(STDOUT_FILENO, &digits[n % 10], 1);
}

int ft_print_int(int n)
{
	int len;

	if (n == INT_MIN)
		return ((write(STDOUT_FILENO, "-2147483648", 11)));
	len = ft_digits_int(n);
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n *= -1;
	}
	ft_put_int(n);
	return (len);
}