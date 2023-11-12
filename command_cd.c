#include "shell.h"

/**
 * command_cd - change the curre directory
 * @commande: two the array of arguments
 * Return: Nothing!!
 */
void command_cd(char **commande)
{
	char *dir = commande[1];
	int r;

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory found\n");
			freearray(commande);
			commande = NULL;
			return;
		}
		freearray(commande);
		commande = NULL;
	}

	r = chdir(dir);
	if (r == -1)
	{
		freearray(commande);
		commande = NULL;
		perror("cd");
	}
	freearray(commande);
	commande = NULL;
}
