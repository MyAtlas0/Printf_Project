#include "main.h"

/**
 * print_number - Prints a long integer.
 *
 * @num: Variable representing the number to print.
 *
 * @count: Returns the curent character count.
 *
 * Return: The updated character count after printing.
 */

int print_number(long num, int count)
{
	if (num < 0)
	{
		count += write_char('-');
		num = -num;
	}
	if (num > 9)
	{
		count = print_number(num / 10, count);
	}
	return (count + write_char(num % 10 + '0'));
}


/**
 * handle_char - function to handle the %c format specifier.
 *
 * @arg: The va_list containing the character to be printed.
 *
 * Return: Returns the number of chaacters printed.
 */

int handle_char(va_list arg)
{
	int count = 0;
	char print_c;

	print_c = va_arg(arg, int);
	count = write_char(print_c);

	return (count);
}


/**
 * handle_string - Handles the %s format specifier
 *
 * @arg: The va_list containing the character to be printed.
 *
 * Return: Returns the number of chaacters printed.
 */

int handle_string(va_list arg)
{
	int count = 0;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += write_char(*str);
		str++;
	}
	return (count);
}


/**
 * handle_integer - Handles the %d and %i format specifiers
 *
 * @arg: The va_list containing the character to be printed.
 *
 * Return: Returns the number of characters printed.
 */

int handle_integer(va_list arg)
{
	int count = 0;
	int num;

	num = va_arg(arg, int);
	count = print_number(num, count);

	return (count);
}


/**
 * handle_binary - Handles teh %b  format specifier;
 *
 * @arg: The va_list containing the character to be printed.
 *
 * Return: Returns the number of chaacters printed.
 */

int handle_binary(va_list arg)
{
	int count = 0;
	unsigned int num;

	num = va_arg(arg, unsigned int);
	count = print_binary(num, count);

	return (count);
}

