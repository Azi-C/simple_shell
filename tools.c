#include "shell.h"

/**
 * freearray - this function for testing!
 * @a: this is a variable matrix
 */
void freearray(char **a)
{
	int i = 0;

	if (!a)
		return;

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

void printerr(char *name, char *cmd, int idx)
{
	char *index;
	char msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}

/**
 * _itoa - function that transfomate an int to a string
 * @n: the int
 * Return: the int into char
 */

char *_itoa(int n)
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
 * reverse_str - reverse a strings
 * @str: the string
 * @len: the length of the string
 * Return: the string reversed
 */

void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}

}

/**
 * is_positive - verify if a variable is a number
 * @str: the string
 * Return: 1 if str is a positif number, 0 otherwise
 */

int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
