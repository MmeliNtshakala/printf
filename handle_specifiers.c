#include "main.h"


/* Helper function to convert integer to string */
static void int_to_str(unsigned int num, int base, char *num_str, int *num_len)
{
    const char *digits = "0123456789ABCDEF";
    int index = 0;

    while (num > 0)
    {
        num_str[index] = digits[num % base];
        num /= base;
        index++;
    }
    *num_len = index;
}

void handle_u(va_list args)
{
    unsigned int uint_arg = va_arg(args, unsigned int);
    int num_len = 0;
    char num_str[20]; /* Assuming max unsigned int digits */
    char ch;

    int_to_str(uint_arg, 10, num_str, &num_len);

    while (num_len > 0)
    {
        num_len--;
        ch = num_str[num_len];
        write(1, &ch, 1);
    }
}

void handle_o(va_list args)
{
    unsigned int uint_arg = va_arg(args, unsigned int);
    int num_len = 0;
    char num_str[20]; /* Assuming max unsigned int digits */
    char ch;

    int_to_str(uint_arg, 8, num_str, &num_len);

    while (num_len > 0)
    {
        num_len--;
        ch = num_str[num_len];
        write(1, &ch, 1);
    }
}

void handle_x(va_list args)
{
    unsigned int uint_arg = va_arg(args, unsigned int);
    int num_len = 0;
    char num_str[20]; /* Assuming max unsigned int digits */
    char ch;

    int_to_str(uint_arg, 16, num_str, &num_len);

    while (num_len > 0)
    {
        num_len--;
        ch = num_str[num_len];
        write(1, &ch, 1);
    }
}

void handle_X(va_list args)
{
    unsigned int uint_arg = va_arg(args, unsigned int);
    int num_len = 0;
    char num_str[20]; /* Assuming max unsigned int digits */
    char ch;

    int_to_str(uint_arg, 16, num_str, &num_len);

    while (num_len > 0)
    {
        num_len--;
        ch = num_str[num_len];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A'; /* Convert to uppercase */
        }
        write(1, &ch, 1);
    }
}

