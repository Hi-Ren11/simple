#include "gmama.h"

/**
 * _strdup - duplicates a string in new allocated memory.
 * @s: pointer to string to duplicate.
 *
 * Return: pointer to new memory address of duplicate.
 */
char *_strdup(char *s)
{
	size_t loop, len;
	char *dup;

	loop = len = 0;
	while (s[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));

	if (!dup)
		return (NULL);

	for (loop = 0; loop < len; loop++)
	{
		dup[loop] = s[loop];
	}

	dup[loop] = '\0';

	return (dup);
}


/**
  * _strcmp - compares two strings
  * @str1: first string
  * @str2: second string
  *
  * Return: 0 if they are equal, 1 if not equal
  */

int _strcmp(char *str1, char *str2)
{
	for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++)
	{
		if (*str1 != *str2)
		{
			return (1);
		}
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0);
	}

	return (1);
}


/**
  * _strlen - counts length of a string
  * @str: string
  *
  * Return: number of string
  */

size_t _strlen(char *str)
{
	char *s = str;
	size_t num_char;

	num_char = 0;
	if (str == NULL)
		return (num_char);

	while (*s++ != '\0')
		num_char++;

	return (num_char);
}
