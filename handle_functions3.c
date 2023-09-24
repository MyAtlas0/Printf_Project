#include "main.h"

/**
 * handle_special_strings - Handles the %S format specifier for non_printables
 *
 * @arg: The va_list containing the character string.
 *
 * Return: returns the number of characters printed.
 */

int handle_special_strings(va_list arg)
{
	int count = 0;
	char *ptr;

	ptr = va_arg(arg, char *);
	if (ptr == NULL)
	{
		ptr = "(null)";
	}
	while (*ptr)
	{
		if ((*ptr < 32 && *ptr >= 0) || *ptr >= 127)
		{
			count += write_char('\\');
			count += write_char('x');

			if (*ptr < 16)
			{
				count += write_char('0');
			}
			print_hex(*ptr, count, 1);
		}
		else
		{
			count += write_char(*ptr);
		}
		ptr++;
	}
	return (count);
}


