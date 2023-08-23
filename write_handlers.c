#include "main.h"
/*********WRITE HANDLE *******/
/**
 * handle writerchar- prints a charecter
 * @c: charecter to be printed.
 * @buffer: buffer array to handle print.
 * @flags counts active flags
 * @width: width specifier
 * @precision:precision specifier
 * @size: size specifier
 *
 * Return number of chars printed.
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	/* char is stored at left and padding at buffers right */
	int i =0;
	char padd = ' ';

	UNUSED_PARAM(precision);
	UNUSED_PARAM(size);

	if (flags & FLAG_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] ='\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE -1] ='\0';
		for(i = 0; i < width -1; i++)
			buffer[BUFFER_SIZE - i -2] = padd;

		if (flags &FLAG_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFFER_SIZE - i -1], width -1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i -1], width -1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/****** WRITE NUMBER ********/
/**
 * write_number - print a num
 * @is_negative: shows negative numbers
 * @ind: index where numbers start
 * @buffer:buffer array handles print
 * @flags : counts active flags 
 * @width : width specifier
 * @size: size specfier
 *
 * Return: Number of cars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind -1;
	char padd =' ', extra_ch =0;
	
	UNUSED_PARAM(size);

	if ((flags &FLAG_ZERO) && !(flags & FLAG_MINUS))
		padd ='0';

	if(is_negative)
		extra_ch = '-';
	else if (flags & FLAG_PLUS)
		extra_ch = '+';
	else if (flags & FLAG_SPACE)
		extra_ch = ' ';
	return write_number(ind, buffer, flags, width, precision, length, padd, extra_ch);
}

/**
 * write_num - writes number using buffer
 * @ind: index where numbers start
 * @buffer : buffer array to handle print
 * @flags : counts active flags 
 * @width : width specifier
 * @prec : precision soecifier
 * @length: num length
 * @padd : padding charecter
 * extra_c : extra charecter 
 *
 * Return: number of printed chars
 */
int write_number(int ind, char buffer[], int flags, int width,
		int prec, int length, char padd, char extra_c)
{
	int i, padd_start = 1;
	if (prec == 0 && ind == BUFFER_SIZE -2 && buffer[ind] == '0' && width == 0)
		return 0; /* printf(".0d", 0) no char is printed */
	if (prec == 0 && ind == BUFFER_SIZE -2 && buffer[ind] == '0')
	{
		buffer[ind] = padd = ' ';
	}
	if (prec > 0 && prec < length)
	{
		padd = ' ';
	}
	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length +1; i++)
		{
			buffer[i] = padd;
		}
		buffer[i] = '\0';
		if (flags & FLAG_MINUS && padd == ' ' )
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return write(1, &buffer[ind], length), + write(1, &buffer[1], i - 1);
		}
		else if (!(flags & FLAG_MINUS) && padd == ' ')
		{
			if(extra_c)
				buffer[--ind] = extra_c;
			return write(1, &buffer[1], i - 1) + write(1, &buffer[ind],length);
		}
		else if (!(flags & FLAG_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return write(1, &buffer[ind], length);
}
