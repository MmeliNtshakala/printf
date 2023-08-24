#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: The list of arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char char_arg;
    char *str_arg;
    int int_arg;
    unsigned int uint_arg;
    int temp;
    int num_len;
    char num_str[20]; /* Assuming max int digits */

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char_arg = (char)va_arg(args, int);
                write(1, &char_arg, 1);
                count++;
            }
            else if (*format == 's')
            {
                str_arg = va_arg(args, char *);
                while (*str_arg)
                {
                    write(1, str_arg, 1);
                    str_arg++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int_arg = va_arg(args, int);
                temp = int_arg;
                num_len = 0;
                if (int_arg < 0)
                {
                    write(1, "-", 1);
                    count++;
                    temp = -temp;
                }
                if (temp == 0)
                {
                    write(1, "0", 1);
                    count++;
                }
                else
                {
                    while (temp > 0)
                    {
                        num_str[num_len] = (temp % 10) + '0';
                        temp /= 10;
                        num_len++;
                    }
                    while (num_len > 0)
                    {
                        num_len--;
                        write(1, &num_str[num_len], 1);
                        count++;
                    }
                }
            }
            else if (*format == 'u')
            {
                uint_arg = va_arg(args, unsigned int);
                /* Convert uint_arg to a string in base 10 */
                /* Use write to print the string */
            }
            else if (*format == 'b')
            {
                uint_arg = va_arg(args, unsigned int);
                temp = uint_arg;
                num_len = 0;
                if (temp == 0)
                {
                    write(1, "0", 1);
                    count++;
                }
                else
                {
                    while (temp > 0)
                    {
                        num_str[num_len] = (temp % 2) + '0';
                        temp /= 2;
                        num_len++;
                    }
                    while (num_len > 0)
                    {
                        num_len--;
                        write(1, &num_str[num_len], 1);
                        count++;
                    }
                }
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);

    return (count);
}
