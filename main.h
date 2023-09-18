#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct Formatspec - Represents format specifiers for _printf.
 *
 * @spec: Format specifier character ( 'c', 's', '%', 'd', 'i').
 *
 * This structure is used to represent format specifiers for the custom printf
 *	implementation. The 'spec' field stores the format specifier character.
 */

typedef struct Formatspec
{
	char spec;
} Formatspec;

/** Prototype function, its declaration **/

int _printf(const char *format, ...);

void write_char(char c);
void print_string(const char *str);
void print_char(int c);
void print_int(int n);

#endif /** MAIN_H **/
