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
 * Return: amount of chars printed or -1 for % error
 */
int _printf(const char *format, ...)
{
	va_list argument;
	char const *tmp = format;
	int i = 0, ln = 0, countfmt = 0, countarg = 0, limit = 0;

	va_start(argument, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			ln = _print_spec(format[i + 1], argument);
			countarg += ln;
			if (ln != 0)
			{
				i++;
				if (format[i + 1] == '\0')
				{
					va_end(argument);
					return (countfmt + countarg);
				}
				else
					limit++;
			}
			else if (ln == 0)
			{
				if (module_check(tmp, i) == -1)
					return (-1);
				i = module_check(tmp, i);
			}
		}
		countfmt += control_put(tmp, limit, i);
		limit = 0;
	}
	va_end(argument);
	return (countfmt + countarg);
}
