#include "main.h"

/**
 * get size - calculates the size to cast the arguement
 * @format: Formatted string in which to print the arguments
 * @i: list argumentsto be printed
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;
	if (format[curr_i] == 'l')
		size = SIZE_LONG;
	else if (format[curr_i] == 'h')
		size = SIZE_SHORT;
	if (size == 0)
		*i = curr_i -1;
	else
		*i = curr_i;
	return size;
}
