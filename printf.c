#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - prints output according to a format.
 * @format: format string containing directives.
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list arg;
    char *str_arg;

    va_start(arg, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 's':
                    str_arg = va_arg(arg, char *);
                    if (str_arg == NULL)
                        str_arg = "(null)";
                    printed_chars += printf("%s", str_arg);
                    break;

                case 'c':
                    printed_chars += printf("%c", va_arg(arg, int));
                    break;

                case 'd':
                case 'i':
                    printed_chars += printf("%d", va_arg(arg, int));
                    break;

                case '%':
                    printed_chars += printf("%%");
                    break;

                default:
                    printed_chars += printf("%%%c", *format);
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(arg);

    return (printed_chars);
}

