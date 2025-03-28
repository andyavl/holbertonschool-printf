#include <unistd.h>

/**
 * _putchar - writes a character
 * @c: character
 * Return: 1
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_d - prints digits or hexadecimal
 * @n: number to print
 * @base: limit
 * Return: printed values and count
 */
int print_d(long n, int base)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
			return (print_d(-n, base) + 1);
	}
	else if (n < base)
	{
		return (_putchar(symbols[n]));
	}
	else
	{
		count = print_d(n / base, base);
		return (count + print_d(n % base, base));
	}
}
