#include "shell.h"

/**
 * main - Simple Shell main function
 * @ac: Number of Arguments
 * @argv: Array containing the Arguments
 * Return: 0 Always (sucess)
 */

int main(int ac, char **argv)
{
	char *ligne = NULL;
	char **command = NULL;
	int status = 0;
	(void) ac;


	while (1)
	{
		ligne = read_commands();
		if (ligne == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			return (status);
		}

		command = tokenizer(ligne);
		if (!command)
			continue;


		status = _execute(command, argv);
	}
}
