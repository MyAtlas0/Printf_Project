#include "main.h"

/**
 * write_char - this function prints the characters to standard output
 *
 * @c: argument for the character to print
 */

void write_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_string - function for printing a string
 *
 * @str: variable for string
 */

void print_string(const char *str)
{
	while (*str)
	{
		write_char(*str);
		str++;
	}
}

/**
 * print_char - functon to print characters
 *
 * @c: variabal for character argument
 */

void print_char(int c)
{
	write_char(c);
}

/**
 * print_int - function for printing an integar
 *
 * @n: variable for an integar argument
 */

void print_int(int n)
{
	int i, len;
	char buffer[20];

	len = snprintf(buffer, sizeof(buffer), "%d", n);
	for (i = 0; i < len; i++)
	{
		write_char(buffer[i]);
	}
}
