#include "main.h"

/**
 *
 *
 *
 *
 *
 *
 *
 */

int _printf(const char *format, ...)
{
	int print_out = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			switch (*format)
			{
				case 'c':
				{
					print_char(va_arg(args, int));
					break;
				}
				case 's':
				{
					print_char(va_arg(args, char *));
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
		else
		{
			write_char(*format);
		}
		format++;
	}
	va_end(args);
	return (print_out);
}
