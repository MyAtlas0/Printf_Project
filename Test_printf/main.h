#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>


/** struct: represents format specifiers **/

typedef struct
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
