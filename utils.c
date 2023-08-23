#include "main.h"
/**
 * is_printable - Evaluates if char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable,0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c< 127)
		return (1);
	return(0);
}

/**
 * append_hexa_code - append ASCII in the hexadecimal code to buffer
 * @buffer: Array of chars
 * @i : index to start appending
 * @ascii_code : ASCII code
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'X';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if char is a digit
 * @c: char to be evalued
 *
 * Return:1 if c is digit,0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - Casts a nu,ber to the specified size
 * @num: number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value
 */
long int convert_size_number(long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((short)num);
	return((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the specified size 
 * @num: Number to be casted
 * @size : Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int conver_size_unsgnd(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

