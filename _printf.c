#include "main.h"

/**
 * _printf - Prototype function for creating a Custom printf function.
 *
 * @format: The format string with format specifiers.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int i;
	int char_count = 0;
	va_list args;
	int (*handler_func)(va_list);

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				return (-1);
			}
			if (format[i] == '%')
			{
				char_count += write_char('%');
			}
			else
			{
				handler_func = handlers(format[i]);
				if (handler_func)
				{
					char_count += handler_func(args);
				}
				else
				{
					char_count += handle_unknown(args, format[i]);
					char_count += 2;
				}
			}
		}
		else
		{
			char_count += write_char(format[i]);
		}
	}
	va_end(args);
	return (char_count);
}
