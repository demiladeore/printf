#include <unistd.h>
/**
* _putchar - write the aurgument to stdout
* Return: Always 1 Success
* @c: aurgument to print
*/

int _putchar (char c)
{
	return (write(1, &c, 1));
}
