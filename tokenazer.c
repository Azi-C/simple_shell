#include "shell.h"

/**
 * tokenizer - this is a function that return the commands
 * @ligne: the command
 * Return: two the array
 */

char **tokenizer(char *ligne)
{
	char *tmp = NULL;
	char **command = NULL;
	int c = 0;
	int i = 0;
	char *token = NULL;

	if (!ligne)
		return (NULL);
	tmp = _strdup(ligne);
	token = strtok(tmp, DEL);
	if (token == NULL)
	{
		free(tmp);
		tmp = NULL;
		free(ligne);
		ligne = NULL;
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, DEL);
	}
	free(tmp);
	tmp = NULL;

	command = malloc(sizeof(char *) * (c + 1));
	if(!command)
	{
		free(ligne);
		ligne = NULL;
		return (NULL);
	}

	token = strtok(ligne, DEL);

	while(token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DEL);
		i++;
	}
	free(ligne);
	ligne = NULL;
	command[i] = NULL;
	return (command);
}
