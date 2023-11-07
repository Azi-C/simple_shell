#include "shell.h"

/**
 * read_commands - this is a function that read the commands in terminal
 * Return:the string!!
 */

char *read_commands(void)
{
	size_t length = 0;
	char *ligne = NULL;
	size_t a;

	if (isatty(STDIN_FILENO == 1))
		write(STDOUT_FILENO, "$ ", 2);
	a = getline(&ligne, &length, stdin);
	if (a == (size_t)-1)
	{
		free(ligne);
		return (NULL);
	}

	return (ligne);
}
