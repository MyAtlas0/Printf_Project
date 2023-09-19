#include "main.h"

/**
 * write_char - Function to Write a character to the standard output.
 *
 *  @c: The character to print.
 *
 * Return: The number of characters printed (1 if successful, -1 on error).
 */

int write_char(char c)
{
	return (write(1, &c, 1));
}
