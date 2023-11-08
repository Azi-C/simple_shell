#include "shell.h"

/*
 * freearray - this function for testing!
 * @a: this is a variable matrix
 * Return:nothh
 */
void freearray(char **a)
{
	if (!a)
		return ;
	for (i = 0; a[i]; i++)
	{
		free(a[i]);
		a[i] = NULL;
	}
	free(a);
	a = NULL;
}
