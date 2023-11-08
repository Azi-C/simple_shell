#include "shell.h"

/**
 * _execute - this is the function that run the commands
 * @commands: this is the variable contient the commands
 * @av: the variable
 * @idx: the index of the command
 * Return: integer
 */

int _execute(char **commands, char **av, int idx)
{
	int status;
	pid_t child;
	char *full_cmd;

	full_cmd = _getpath(commands[0]);
	if (!full_cmd)
	{
		printerr(av[0], commands[0], idx);
		freearray(commands);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, commands, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			freearray(commands);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(commands);
		free(full_cmd);
		full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
