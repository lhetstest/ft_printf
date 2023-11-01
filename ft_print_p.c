#include "ft_printf.h"

static size_t ft_digits_p(unsigned long long n)
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

static void ft_put_p(unsigned long long addr)
{
	static char digits[] = "0123456789abcdef";

	if (addr)
		ft_put_p(addr / 16);
	write(STDIN_FILENO, &digits[addr % 16], 1);
}

int ft_print_p(void *addr)
{
	if (addr == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	write(STDOUT_FILENO, "0x", 2);
	ft_put_p((unsigned long long)addr);
	return (ft_digits_p((unsigned long long)addr) + 2);
}