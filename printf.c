#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: Format string.
 * @...: Variable arguments.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;
	char buffer[1024]; /* Local buffer to accumulate characters */
	int buffer_index = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		int field_width = 0;
		int precision = -1;

		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Handle conversion specifier cases */
			switch (*format)
			{
				/* ... (Previous cases) */

				case 'S':
					/* Handle %S */
					{
						/* Existing code for %S */
						break;
					}

				case 'p':
					/* Handle %p */
					{
						/* Existing code for %p */
						break;
					}

				case 'u':
				case 'o':
				case 'x':
				case 'X':
				case 'd':
				case 'i':
					/* Handle %u, %o, %x, %X, %d, %i */
					{
						char flag_char = *format;
						(void)flag_char;

						/* Handle flag characters */
						if (format[1] == '+')
						{
							format++;
						}
						else if (format[1] == ' ')
						{
							format++;
						}
						else if (format[1] == '0')
						{
							format++; /* Move past the '0' flag */
						}

						/* Handle length modifiers */
						if (format[1] == 'l' || format[1] == 'h')
						{
							format++;
						}

						/* Handle field width */
						while (*format >= '0' && *format <= '9')
						{
							field_width = field_width * 10 + (*format - '0');
							format++;
						}

						/* Handle precision */
						if (*format == '.')
						{
							format++;
							precision = 0;
							while (*format >= '0' && *format <= '9')
							{
								precision = precision * 10 + (*format - '0');
								format++;
							}
						}

						format++;

						/* Rest of the implementation for %u, %o, %x, %X, %d, %i */
						/* Use flag_char, length modifiers, field width, and precision as needed */
						break;
					}

				/* ... (Remaining cases) */

				default:
					/* Handle unknown conversion specifiers */
					/* Optionally print an error message or just ignore */
					break;
			}
		}
		else
		{
			if (buffer_index >= (int)(sizeof(buffer) - 1))
			{
				/* Buffer is full, write its content and reset index */
				write(1, buffer, buffer_index);
				chars_printed += buffer_index;
				buffer_index = 0;
			}

			buffer[buffer_index++] = *format;
			chars_printed++;
		}

		format++; /* Move to the next character in the format string */
	}

	/* Write any remaining characters in the buffer */
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		chars_printed += buffer_index;
	}

	va_end(args);
	return chars_printed;
}
