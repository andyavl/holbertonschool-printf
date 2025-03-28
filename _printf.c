#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct t
{
	char *s;
	int (*f)(va_list argument);
}type;

int _putchar(int c)
{
	return write(1, &c, 1);
}

int print_d(long n, int base)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdefABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
			return print_d(-n, base) + 1;
	}
	else if (n < base)
	{
		return _putchar(symbols[n]);
	}
	else
	{
		count = print_d(n / base, base);
		return count + print_d(n % base, base);
	}
}


int type_char_print(va_list argument)
{
	int ch = va_arg(argument, int);
	return write(1, &ch, 1);
}

int type_string_print(va_list argument)
{
	char *arg = va_arg(argument, char*);
	int j;

	for (j = 0; arg[j] != '\0'; j++)
		_putchar((int)arg[j]);
	return(j);
}

int type_digit_print(va_list argument)
{
	int r = 0;

	r += print_d((long)(va_arg(argument, int)), 10);
	return (r);
}

int type_hexa_print(va_list argument)
{
	int r = 0;

	r += print_d((long)(va_arg(argument, unsigned int)), 16);
	return (r);
}


int _print_spec(char spc, va_list argument)
{
	int i;

	type specifier[] = {
		{"c", type_char_print},
		{"s", type_string_print},
		{"d", type_digit_print},
		{"i", type_digit_print},
		{"x", type_hexa_print},
		{NULL, NULL}
	};

	i = 0;
	while (specifier[i].s != NULL)
	{
		if (*(specifier[i].s) == spc)
			return (specifier[i].f(argument));
		i++;
	}
	return (0);
}

int _printf(const char *format, ...)
{
	va_list argument;
	int i = 0, j = 0, ln = 0, count = 0;

	va_start(argument, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			ln = _print_spec(format[i + 1], argument);
			if(ln != 0)
				i += 2;
			else
			{
				for (j = i + 1; format[j] != '\0'; j++)
				{
					if (format[j] == '%')
					{
						i = j;
						break;
					}
				}
			}
		}
		_putchar(format[i]);
		if (format[i] != '\0')
			count++;
	}
	va_end(argument);
	return (count);
}
