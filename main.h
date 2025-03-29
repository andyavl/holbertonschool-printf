#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>

/**
 *  struct t - struct for _print_spec
 *  @s: specifier
 *  @f: fuction associated with specifier
 */
typedef struct t
{
char *s;
int (*f)(va_list argument);
} type;

int _printf(const char *format, ...);
int _print_spec(char spc, va_list argument);

int type_char_print(va_list argument);
int type_string_print(va_list argument);
int type_digit_print(va_list argument);
int type_hexa_print(va_list argument);

int _putchar(int c);
int print_d(long n, int base);
int module_check(char const *format, int i);
int control_put(char const *format, int limit, int i);

#endif
