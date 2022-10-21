#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _itoa - converts int to string
 * @i: the integer
 * @strout: the string
 * @base: the base to convert
 *
 * Return: converted string
 */
char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);
	return (strout);
}
