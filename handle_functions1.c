#include "main.h"

/**
 * handle_pointer - Function to handle the %p format specifier.
 *
 * @arg: The va_list containing the pointer to print
 *
 * Return: The number of characters printed.
 */

int handle_pointer(va_list arg)
{
	int i;
	int count = 0;
	unsigned long p;
	char hex[16];
	const char *nil_str;
	void *ptr = va_arg(arg, void *);

	if (ptr)
	{
		count += write_char('0');
		count += write_char('x');
		p = (unsigned long)ptr;
		(void)hex[16];

		for (i = 0; i < 16; i++)
		{
			hex[i] = "0123456789abcdef"[p & 0xF];
			p >>= 4;
		}
		for (i = 15; i >= 0; i--)
		{
			count += write_char(hex[i]);
		}
	}
	else
	{
		nil_str = "(nil)";
		while (*nil_str)
		{
			count += write_char(*nil_str);
			nil_str++;
		}
	}
	return (count);
}


/**
 * handle_unknown - Function handle unknown format specifiers.
 *
 * @arg: The va_list containing the unknown specifier.
 *
 * @unknown: Varuable for the unknown character specifiers.
 *
 * Return: The number of characters printed.
 */

int handle_unknown(va_list arg, char unknown)
{
	int count = 0;
	(void)arg;

	count += write_char('%');
	count += write_char(unknown);

	return (count);
}
