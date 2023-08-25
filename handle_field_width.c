#include "main.h"

/**
 * handle_field_width - Handle field width for conversion specifiers
 * @format: The format string
 * @args: The va_list of arguments
 * @idx: The current index in the format string
 * @field_width: Pointer to store the parsed field width
 *
 * Return: The updated index
 */
int handle_field_width(const char *format, int idx, int *field_width)
{
    *field_width = 0;
    if (format[idx] >= '0' && format[idx] <= '9')
    {
        while (format[idx] >= '0' && format[idx] <= '9')
        {
            *field_width = (*field_width) * 10 + (format[idx] - '0');
            idx++;
        }
    }
    return (idx);
}
