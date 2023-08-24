#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>  /* For variadic functions */
#include <stdio.h>

void handle_S(va_list args);
void flush_buffer(void);
void buffered_putchar(char ch);
void buffered_puts(const char *str);


void handle_u(va_list args);
void handle_o(va_list args);
void handle_x(va_list args);
void handle_X(va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */

