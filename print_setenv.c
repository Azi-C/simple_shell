#include "shell.h"

/**
 * print_setenv - Set the value in terminal
 * @commande: Arguments (name and value of the environment variable)
 *
 * Return: 0 or -1
 */
int print_setenv(char **commande)
{
	char *n, *v;

	if (commande[1] == NULL || commande[2] == NULL)
	{
		_puterror("Usage: setenv VARIABLE VALUE\n");
		freearray(commande);
		return (-1);
	}

	n = commande[1];
	v = commande[2];

	if (setenv(n, v, 1) != 0)
	{
		_puterror("setenv");
		freearray(commande);
		return (-1);
	}
	freearray(commande);
	return (0);
}
