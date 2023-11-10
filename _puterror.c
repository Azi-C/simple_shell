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
