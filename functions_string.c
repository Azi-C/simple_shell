#include "shell.h"

/**
 * _strdup - duplicate the string
 * @str: the string
 * Return: a pointer
 */

char *_strdup(const char *str)
{
	int i, j = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (str[j])
		j++;
	ptr = malooc(sizeof(char) * (j + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= j; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - compare string values
 * @s1: input value(string)
 * @s2: input value(string)
 *
 * Return: integer s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _strlen - this function count the number of caracter in a statements
 *
 * @s:this varibale content the string varibale
 * Return:the count value
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 * Return:void
 */
char *_strcat(char *dest, char *src)
{
	int l = 0;
	int j;
	int i = 0;

	while (dest[i] != '\0')
	{
		l++;
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[l] = src[j];
		j++;
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int j = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; j < l ; j++)
	{
		dest[j] = src[j];
	}
	dest[l] = '\0';
	return (dest);
}
