#include "main.h"

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
