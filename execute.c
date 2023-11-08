#include "shell.h"

/**
 * _execute - this is the function that run the commands
 * @commands: this is the variable contient the commands
 * @av: the variable
 * Return: integer
 */

int _execute(char **commands, char **av)
{
	int status;
	pid_t child;

	child = fork();
	if (child == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			perror(av[0]);
			freearray(commands);
			exit(0);
		}
		freearray(commands);
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(commands);
	}
	return (WEXITSTATUS(status));
}
