#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/** PROTOTYPE FUNCTIONS **/

int _printf(const char *format, ...);
int write_char(char c);

int (*handlers(char str))(va_list arg);
int print_number(long num, int count);
int print_binary(unsigned int num, int count);
int handle_char(va_list arg);
int handle_string(va_list arg);
int handle_integer(va_list arg);
int handle_pointer(va_list arg);
int handle_binary(va_list arg);
int handle_unknown(va_list arg, char unknown);

#endif /** MAIN_H **/
