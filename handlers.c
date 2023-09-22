#include "main.h"

/**
 * handlers - Return the appropriate function pointer for a format specifier.
 *
 * @specifier: The format specifier character.
 *
 * Return: A function pointer to the appropriate handler function, or NULL.
 */

int (*handlers(char specifier))(va_list arg)
{
	switch (specifier)
	{
		case 'c':
			return (&handle_char);
		case 's':
			return (&handle_string);
		case 'd':
		case 'i':
			return (&handle_integer);
		case 'p':
			return (&handle_pointer);
		case 'b':
			return (&handle_binary);
		case 'u':
			return (&handle_unsigned_int);
		case 'o':
			return (&handle_octal);
		case 'x':
			return (&handle_hex);
		case 'X':
			return (&handle_upper_hex);
		case 'S':
			return (&handle_special_strings);
		default:
			return (NULL);
	}
}
