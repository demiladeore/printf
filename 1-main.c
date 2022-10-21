#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * main- checks the code
 * @argc: the count of arguments
 * @argv: the array of arguments
 *
 * Return: Always 0 on success
 */
int main()
{
	int ret;
	ret = _printf("%c %d %o %x %s\n", 'A', 10, 100, 1000, "Hello from printf!");
	printf("printf returns %d bytes\n", ret);
	_putchar(ret + '0');
	return 0;
}
