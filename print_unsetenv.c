#include "shell.h"

/**
 * print_unsetenv - Unset an environment variables
 * @commande: the commands
 *
 * Return: 0 or -1
 */
int print_unsetenv(char **commande)
{
	char *n;

	if (commande[1] == NULL)
	{
		_puterror("Usage: unsetenv VARIABLE\n");
		freearray(commande);
		return (-1);
	}

	n = commande[1];

	if (unsetenv(n) != 0)
	{
		_puterror("unsetenv");
		freearray(commande);
		return(-1);
	}
	freearray(commande);
	return (0);
}
