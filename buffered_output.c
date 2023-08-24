#include "main.h"  /* Include the header where BUFFER_SIZE is defined */

static char output_buffer[BUFFER_SIZE];
static int buffer_index = 0;

void flush_buffer(void)
{
    if (buffer_index > 0)
    {
        write(1, output_buffer, buffer_index);
        buffer_index = 0;
    }
}

void buffered_putchar(char ch)
{
    if (buffer_index >= BUFFER_SIZE)
    {
        flush_buffer();
    }
    output_buffer[buffer_index] = ch;
    buffer_index++;
}

void buffered_puts(const char *str)
{
    while (*str)
    {
        buffered_putchar(*str);
        str++;
    }
}

