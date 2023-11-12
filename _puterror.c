#include "shell.h"

/**
 * _puterror - Prints an error messages
 * @r: The error message to printting
 *
 * Return: nothing
 */
void _puterror(char *r)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(r);
	num_written = write(STDERR_FILENO, r, len);
	if (num_written == -1)
	{
		perror("write");
	}
}

/**
 * _puts - printting the string
 * @str: the variable stringg
 *
 * Return: nothing
 */
void _puts(char *str)
{
	size_t len;
	ssize_t num;

	len = _strlen(str);
	num = write(STDOUT_FILENO, str, len);
	if (num == -1)
	{
		perror("write");
	}
}
