#include "shell.h"

/**
 * _getpath - return the path of a command
 * @cmd: the command
 * Return: the path
 */

char *_getpath(char *cmd)
{
	char *path_env;
	char *full_cmd;
	char *dir;
	struct stat st;

	path_env = _getenv("PATH");

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);

		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;

			dir = strtok(NULL, ":");

		}
	}
	free(path_env);
	return (NULL);
}
