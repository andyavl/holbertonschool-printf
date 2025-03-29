#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

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

/**
 * module_check - checks for a % in a string
 * @format: string to check
 * @i: inicial position
 * Return: % position, inicial position or -1
 */
int module_check(char const *format, int i)
{
	int j = 0;

	if (format[i + 1] != '\0')
	{
		for (j = i + 1; format[j] != '\0'; j++)
		{
			if (format[j] == '%')
			{
				return (j);
			}
		}
	}
	else
		return (-1);
	return (i);
}

/**
 * control_put - puts or not a character
 * @format: string to check
 * @limit: if limit is 1 it wont write
 * @i: inicial position
 * Return: 1 if not null byte and no limit, else 0
 */
int control_put(char const *format, int limit, int i)
{
	if (limit != 1)
		_putchar(format[i]);
	if (format[i] != '\0' && limit != 1)
		return (1);
	return (0);
}
