#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_PARAM(x) (void)(x)
#define BUFFER_SIZE 1024

/* Formatting Flags */
#define FLAG_MINUS  1
#define FLAG_PLUS   2
#define FLAG_ZERO   4
#define FLAG_HASH   8
#define FLAG_SPACE 16

/* Data Sizes */
#define SIZE_LONG  2
#define SIZE_SHORT 1

/**
 * STRUCT FMT_SPEC - Format specifier structure
 *
 * @specifier: The format specifier.
 * @function: Pointer to the associated function.
 */
struct fmt_spec
{
	char specifier;
	int (*function)(va_list, char[], int, int, int, int);
};

typedef struct fmt_spec fmt_spec_t;

int custom_printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list, char buffer[], int flags, int width, int precision, int size);

/* Various Functions */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
/*... (other functions) ...*/
int write_unsgnd(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);

/* Utility Functions */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
