#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#define INT_MIN (-2147483647 - 1)
#define UINT_MAX (4294967295U)
#define LONG_MAX 2147483647L
#define ULONG_MAX 4294967295UL



#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>  /* For variadic functions */
#include <stdio.h>
#include <stdint.h> /* For uintptr_t */

void handle_flags(const char *format, va_list args, int idx, char flag);
void handle_p(va_list args);
int handle_length_modifiers(const char *format, va_list args, int idx, char length_modifier);

void handle_S(va_list args);
void flush_buffer(void);
void buffered_putchar(char ch);
void buffered_puts(const char *str);

void handle_p(va_list args);
void handle_u(va_list args);
void handle_o(va_list args);
void handle_x(va_list args);
void handle_X(va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */
