#include "main.h"

/**
 * print_octal - This This Function prints  an unsigned in octal format.
 *
 * @num: Variable for the octal to be printed.
 *
 * @count: Variable for the current character count.
 *
 * Return: The updated character count after printing.
 */

int print_octal(unsigned int num, int count)
{
	if (num > 7)
	{
		count = print_octal(num / 8, count);
	}
	return (count + write_char(num % 8 + '0'));
}



/**
 * handle_octal - Handles the '%o' format specifier for converting octal.
 *
 * @arg: The va_list containing the unsigned int to be printed in octal.
 *
 * Return: The number of characters printed.
 */

int handle_octal(va_list arg)
{
	int count = 0;
	unsigned int num;

	num = va_arg(arg, unsigned int);
	count = print_octal(num, count);
	return (count);
}



/**
 * print_hex - This prints an unsigned int in an hexadecimal format.
 *
 * @num: Variable for the unsigned int to be printed in hexadecimal.
 *
 * @count: Variable for the current character count.
 *
 * @uppercase: 1 for uppercase letters (X), 0 for lowercase letters (x).
 *
 * Return: The updated character count after printing.
 */

int print_hex(unsigned int num, int count, int uppercase)
{
	char value;
	char hexa_decimal[] = "0123456789abcdef";

	if (num > 15)
	{
		count = print_hex(num / 16, count, uppercase);
	}
	value = hexa_decimal[num % 16];
	if (uppercase)
	{
		if (value >= 'a' && value <= 'f')
		{
			value -= 32;
		}
	}
	count += write_char(value);
	return (count);
}



/**
 * handle_hex - Handles the '%x' format specifier for lowercase hexadecimal.
 *
 * @arg: The va_list containing the unsigned int to be printed in hexadecimal.
 *
 * Return: The number of characters printed.
 */

int handle_hex(va_list arg)
{
	int count = 0;
	unsigned int num;

	num = va_arg(arg, unsigned int);
	count = print_hex(num, count, 0);
	return (count);
}



/**
 * handle_upper_hex - Handles '%X' format specifier for uppercase hexadecimal.
 *
 * @arg: The va_list containing the unsigned int to be printed in uppercase.
 *
 * Return: The number of characters printed.
 */

int handle_upper_hex(va_list arg)
{
	int count = 0;
	unsigned int num;

	num = va_arg(arg, unsigned int);
	count = print_hex(num, count, 1);
	return (count);
}
