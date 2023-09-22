#include "main.h"

/**
 * print_binary - Prints an unsigned integer in binary format.
 *
 * @num: Variable for the unsigned int to be printed in binary.
 *
 * @count: Variable for the current character count.
 *
 * Return: The updated character count after printing.
 */

int print_binary(unsigned int num, int count)
{
	if (num > 1)
	{
		count = print_binary(num / 2, count);
	}
	return (count + write_char(num % 2 + '0'));
}



/**
 * handle_pointer - Function to handle the %p format specifier.
 *
 * @arg: The va_list containing the pointer to print
 *
 * Return: The number of characters printed.
 */

int handle_pointer(va_list arg)
{
	int count = 0;
	int i, leading_zeros;
	unsigned long p;
	char hex[16];
	const char *null_str;
	void *ptr = va_arg(arg, void *);

	if (ptr)
	{
		count += write_char('0');
		count += write_char('x');
		p = (unsigned long)ptr;
		(void)hex[16];

		leading_zeros = 1;
		for (i = 0; i < 16; i++)
		{
			hex[i] = "0123456789abcdef"[p & 0xF];
			p >>= 4;
		}

		for (i = 15; i >= 0; i--)
		{
			if (hex[i] != '0' || !leading_zeros)
			{
				count += write_char(hex[i]);
				leading_zeros = 0;
			}
		}
	}
	else
	{
		null_str = "(null)";
		while (*null_str)
		{
			count += write_char(*null_str);
			null_str++;
		}
	}
	return (count);
}



/**
 * handle_unknown - Function handle unknown format specifiers.
 *
 * @arg: The va_list containing the unknown specifier.
 *
 * @specifier: Variable for the unknown character specifiers.
 *
 * Return: The number of characters printed.
 */

int handle_unknown(va_list arg, char specifier)
{
	int count = 0;
	(void)arg;

	count += write_char('%');
	count += write_char(specifier);

	return (count);
}



/**
 * print_unsigned_int - This is a function that prints an unsigned integer.
 *
 * @num: The unsigned int to be printed.
 *
 * @count: The current character count.
 *
 * Return: Updated character count after printing.
 */

int print_unsigned_int(unsigned int num, int count)
{
	if (num > 9)
	{
		count = print_unsigned_int(num / 10, count);
	}
	return (count + write_char(num % 10 + '0'));
}



/**
 * handle_unsigned_int - Handles '%u' format specifier for unsigned int.
 *
 * @arg: The va_list argument containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */

int handle_unsigned_int(va_list arg)
{
	int count = 0;
	unsigned int num;

	num = va_arg(arg, unsigned int);
	count = print_unsigned_int(num, count);
	return (count);
}
