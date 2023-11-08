#include "shell.h"

/**
 * _getenv - gives us the value of an environment variable
 * @var: the environment variable
 * Return: the value of the variable
 */

char *_getenv(char *var)
{
	char *tmp;
	char *key;
	char *value;
	char *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);

		}
		free(tmp);
		tmp = NULL;

	}
	return (NULL);

}
