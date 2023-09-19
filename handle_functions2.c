#include "main.h"

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
	char hexa_decimal[] = "0123456789abcdef";

	if (num > 15)
	{
		count = print_hex(num / 16, count, uppercase);
	}
	if (uppercase)
	{
		return (count + write_char(hexa_decimal[num % 16] - 32));
	}
	return (count + write_char(hexa_decimal[num % 16]));
}
