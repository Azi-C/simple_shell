#include "shell.h"

/**
 * fct_built - this is a function check the commands exit, env...
 * @commande: the commands
 * Return: 0 or 1;
 */

int fct_built(char *commande)
{
	char *buil[] = {
		"exit", "env", "setenv", "cd"
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(commande, buil[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * hd_buil - handling the commands exit and env
 * @commande: commandes
 * @argv: two the arrays
 * @status: value of exit
 * @idx: the integer
 * Return: segmt default
 */

void hd_buil(char **commande, char **argv, int *status, int idx)
{
	(void) argv;
	(void) idx;
	if (_strcmp(commande[0], "exit") == 0)
		exit_shell(commande, status);
	else if (_strcmp(commande[0], "env") == 0)
		print_env(commande, status);


}

/**
 * exit_shell - this funtion that exit the shell terminal
 * @status: the value of exit
 * Return: sgmt default
 */

void exit_shell(char **commande, int *status)
{
	freearray(commande);
	exit(*status);
}

/**
 * print_env - handling the command evn in the terminal shell
 * @commande: this is the commands
 * @status: the value of exit
 * Return: sgmt default
 */

void print_env(char **commande, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(commande);
	(*status) = 0;
}
