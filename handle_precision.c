#include "main.h"

/**
 * handle_precision - Handle precision for conversion specifiers
 * @format: The format string
 * @idx: The current index in the format string
 *
 * Return: The updated index
 */
int handle_precision(const char *format, int idx)
{
    int precision = -1; /* Default value for precision */

    /* Check if precision is specified */
    if (format[idx] == '.')
    {
        idx++; /* Move to the next character after the '.' */
        
        /* Parse the precision value from the format string */
        if (format[idx] >= '0' && format[idx] <= '9')
        {
            precision = 0;
            while (format[idx] >= '0' && format[idx] <= '9')
            {
                precision = precision * 10 + (format[idx] - '0');
                idx++;
            }
        }
    }

    return (precision);
}
