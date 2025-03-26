#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - print format
 * @format: format of the imput
 * Return: The imput
 */

int _printf(const char *format, ...)
{
	int len = 0;
	va_list arg_list;
	int i;
	int j;
	char *str;

	va_start(arg_list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
					str = va_arg(arg_list, char *);

				for (j = 0; str[j] != '\0'; j++)
				{
					putchar(str[j]);
					len++;
				}
			}
			else
			{
				putchar(format[i]);
				len++;
			}
		}
		va_end(arg_list);
	}
	return (len);
}
