#include "gmama.h"

/**
 * check_slash - checks if there are any slashes in the command
 * @str: input string
 * Return: 1 if slash is found 0 if slash is not found
 */

int check_slash(char *str)
{
	while (*str != '\0')
	{
		if (*str == '/')
			return (1);
		str++;
	}
	return (0);
}
