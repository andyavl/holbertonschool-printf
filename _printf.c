#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * _print_spec - selects fuction based on specifier
 * @spc: specifier to compare
 * @argument: argument to use on selected fuction
 * Return: result of selected fuction or 0 specifier doesnt match
 */
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

/**
 * _printf - fuctions that outputs a string, temu printf
 * @format: values to print
 * Return: amount of chars printed
 */
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
			if (ln != 0)
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
