#include "shell.h"

/*
 * freearray - this function for testing!
 * @a: this is a variable matrix
 * Return:nothh
 */
void freearray(char **a)
{
	int i = 0;
	if (!a)
		return ;
	for (i = 0; a[i]; i++)
	{
		free(a[i]);
		a[i] = NULL;
	}
	free(a);
	a = NULL;
}

/**
 * printerr - prints an error
 * @name: the shell name
 * @cmd: la command
 * @idx: index of the command
 */

void printerr(char *name, char *md, int idx)
{
	char *index;

	index = _itoa(idx);
}

/**
 * _itoa - functions that transfomate an int to a string
 * @n: the int
 * Return: the int into char
 */

char _*itoa(int n)
{
	char buffer[25];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_str(buffer, i);

	return (_strdup(buffer));
}

/**
 * reverse_str - reverse a string
 * @str: the string
 * @len: the length of the string
 * Return: the string reversed
 */

void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len -a;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
