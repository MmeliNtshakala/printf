#include "main.h"

/**
 * handle_flags - Handle flag characters for non-custom conversion specifiers
 * @format: The format string
 * @args: The va_list of arguments
 * @idx: The current index in the format string
 * @flag: The flag character to handle
 *
 * Return: None
 */
void handle_flags(const char *format, va_list args, int idx, char flag)
{
    if (flag == '+')
    {
        /* Handle '+' flag: Print the sign for positive numbers */
        if (format[idx] == 'd' || format[idx] == 'i') {
            int int_arg = va_arg(args, int);
            if (int_arg >= 0) {
                buffered_putchar('+');
            }
        }
    }
    else if (flag == ' ')
    {
        /* Handle ' ' flag: Print a space character before positive numbers */
        if (format[idx] == 'd' || format[idx] == 'i') {
            int int_arg = va_arg(args, int);
            if (int_arg >= 0) {
                buffered_putchar(' ');
            }
        }
    }
    else if (flag == '#')
    {
        /* Handle '#' flag: Add the '#' prefix for octal and hexadecimal conversions */
        if (format[idx] == 'o' || format[idx] == 'x' || format[idx] == 'X') {
            buffered_putchar('0');
            if (format[idx] == 'x' || format[idx] == 'X') {
                buffered_putchar(format[idx]);
            }
        }
    }
    else
    {
        /* Invalid flag character */
        /* Handle error or ignore the flag */
    }
}
