#include "main.h"

/**
 * _printf - prototype function for implementing _printf
 *
 * condition - the _printf iterates through the format string, detecting
 *		format specifiers '%'. and for each specifier, it calls the
 *		appropriate pring function based on the specifier typr, and
 *		writes its corresponding argument to the standard output.
 *
 * @format: this is the formating string for handling specifiers
 *
 * Return: The number of characters printed (excluding the null terminator)
 */

int _printf(const char *format, ...)
{
	int print_out = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write_char(*format);
			print_out++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			switch (*format)
			{
				case 'c':
				{
					print_char(va_arg(args, int));
					break;
				}
				case 's':
				{
					print_string(va_arg(args, char *));
					break;
				}
				case '%':
				{
					write_char('%');
					break;
				}
				case 'd':
				case 'i':
				{
					print_int(va_arg(args, int));
					break;
				}
				default:
				{
					write_char('?');
					break;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (print_out);
}
