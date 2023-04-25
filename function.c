#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    char *str_arg;
    char char_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    char_arg = va_arg(args, int);
                    putchar(char_arg);
                    printed_chars++;
                    break;

                case 's':
                    str_arg = va_arg(args, char *);
                    if (str_arg == NULL)
                    {
                        printf("(null)");
                        printed_chars += 6;
                    }
                    else
                    {
                        printf("%s", str_arg);
                        printed_chars += strlen(str_arg);
                    }
                    break;

                case '%':
                    putchar('%');
                    printed_chars++;
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
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

    va_end(args);

    return printed_chars;
}

