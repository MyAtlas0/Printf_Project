#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int len_1 = 42;
	int len_2 = 100;
	char c = 'A';
	char *str = "_Printf currently running!!!";
	char *str_1 = "Printf currently running!!!";

	_printf("Integar: %d%%\nCharacter: %c\nString:%s\n", len_1, c, str);
	printf("Integar: %d%%\nCharacter: %c\nString:%s\n", len_1, c, str_1);
	_printf("Length:[%d, %i]\n", len_2, len_1);
	printf("Length:[%d, %i]\n", len_1, len_2);

	return (0);
}
