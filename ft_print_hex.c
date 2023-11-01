#include "ft_printf.h"

static size_t ft_digits_h(unsigned int n)
{
	size_t digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void ft_put_hex(unsigned int num, bool upper_case)
{
	static char upper_digits[] = "0123456789ABCDEF";
	static char lower_digits[] = "0123456789abcdef";

	if (num >= 16)
		ft_put_hex((num / 16), upper_case);
	if (upper_case == true)
		write(STDOUT_FILENO, &upper_digits[num % 16], 1);
	else
		write(STDOUT_FILENO, &lower_digits[num % 16], 1);
}

int ft_print_hex(unsigned int num, bool upper_case)
{
	ft_put_hex(num, upper_case);
	return (ft_digits_h(num));
}
