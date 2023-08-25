#include "main.h"

/**
 * handle_p - Handles the 'p' conversion specifier
 * @args: The va_list containing the arguments
 *
 * Description: Converts a pointer argument to a hexadecimal string
 * and prints it.
 */
void handle_p(va_list args)
{
    void *ptr_arg = va_arg(args, void *);
    char hex_chars[] = "0123456789abcdef";
    uintptr_t ptr_value = (uintptr_t)ptr_arg;
    char hex_str[16];
    char ch;
    int i;

    hex_str[0] = '0';
    hex_str[1] = 'x';

    for (i = sizeof(uintptr_t) * 2 + 1; i >= 2; i--)
    {
        ch = hex_chars[ptr_value & 0xf];
        hex_str[i] = ch;
        ptr_value >>= 4;
    }

    hex_str[sizeof(uintptr_t) * 2 + 2] = '\0';

    buffered_puts(hex_str);
}
