#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * type_char_print - calls write to print a char
 * @argument: argument to print
 * Return: write
 */
int type_char_print(va_list argument)
{
	int ch = va_arg(argument, int);

	return (write(1, &ch, 1));
}

/**
 * type_string_print - calls _putchar to print a string
 * @argument: argument to print
 * Return: amount of chars printed
 */
int type_string_print(va_list argument)
{
	char *arg = va_arg(argument, char*);
	int j;

	for (j = 0; arg[j] != '\0'; j++)
		_putchar((int)arg[j]);
	return (j);
}

/**
 * type_digit_print - calls print_d to print digits
 * @argument: argument to print
 * Return: amount of digit printed
 */
int type_digit_print(va_list argument)
{
	int r = 0;

	r += print_d((long)(va_arg(argument, int)), 10);
	return (r);
}

/**
 * type_hexa_print - calls print_d to print hexadecimal values
 * @argument: argument to print
 * Return: amount of chars printed
 */
int type_hexa_print(va_list argument)
{
	int r = 0;

	r += print_d((long)(va_arg(argument, unsigned int)), 16);
	return (r);
}
