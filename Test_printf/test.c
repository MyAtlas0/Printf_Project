#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
        int len = 42;
        char c = 'A';
        char *str = "_Printf currently running!!!";

        _printf("Integar: %d%%\nCharacter: %c\nString:%s\n", len, c, str);
        printf("Integar: %d%%\nCharacter: %c\nString:%s\n", len, c, str);

        return (0);
}
