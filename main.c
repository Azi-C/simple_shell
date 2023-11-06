#include "shell.h"

/**
 * main - Simple Shell main function
 * @ac: Number of arguments
 * @argv: Array containing the arguments
 * Reurn: 0 Always (sucess)
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status;
	(void) ac;

	while (1)
	{
		line = read_line();

		command = tokenizer(line);

		status = _execute(command, argv);
	}
}
