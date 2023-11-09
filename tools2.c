#include "shell.h"

/**
 * _atoi - transform an ASCII to an integer
 * @str: the element in ASCII form
 * Return: the element in int
 */

int _atoi(char *str)
{
	int i;
	int n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}

	return (n);
}
