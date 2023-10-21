#include "ft_printf.h"

static char *ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
	int count;
	int remainder;
	char character;

	count = 0;
	if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			character = HEXALOW[remainder];
		else
			character = HEXAUP[remainder];
		n /= 16;
		iteration = 1;
		count += ft_recursive_hex(f, n, iteration);
		count += ft_putchar_fd(character, 1);
	}
	return (count);
}