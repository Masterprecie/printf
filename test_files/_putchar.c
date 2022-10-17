#include <unistd.h>
/**
 * _putchar - function to return character to stdout
 *
 * @c -  Input Char
 *
 * return int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
