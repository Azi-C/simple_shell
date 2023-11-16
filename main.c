#include "shell.h"

/**
 * main - Simple Shell main function source code
 * @ac: Number of Arguments
 * @argv: Array containing the Arguments
 * Return: 0 Always (sucess)
 */

int main(int ac, char **argv)
{
	char *ligne = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void) ac;

fct_buil
	while (1)
	{
		ligne = read_commands();
		if (ligne == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDIN_FILENO, "\n", 1);
			return (status);
		}
		idx++;

		command = tokenizer(ligne);
		if (!command)
			continue;

		if (fct_built(command[0]))
			hd_buil(command, argv, &status, idx);
		else
			status = _execute(command, argv, idx);

	}
}
