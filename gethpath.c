#include "gmama.h"

/**
 * get_path - get the env path and tokenizes it into a array.
 * @modify_path: pointer to store modified path string into
 *
 * Return: array / double pointer.
 */
char **get_path(char **modify_path)
{
	char **token_ptr;
	char *path, *delim;
	unsigned int i, j, num_char;

	delim = ":";
	path = _getenv("PATH");
	num_char = _strlen(path);
	*modify_path = malloc(sizeof(char) * (num_char + 2));
	if (num_char == 0)
	{
		(*modify_path)[0] = '.';
		(*modify_path)[1] = '\0';
	}
	else
	{
		for (i = 0, j = 0; path[i] != '\0'; i++)
		{
			if (i == 0 && path[i] == ':')
			{
				(*modify_path)[j++] = '.';
				(*modify_path)[j++] = path[i];
			}
			else if (i == num_char - 1 && path[i] == ':')
			{
				(*modify_path)[j++] = path[i];
				(*modify_path)[j++] = '.';
			}
			else if (path[i] == ':' && path[i + 1] == ':')
			{
				(*modify_path)[j++] = path[i];
				(*modify_path)[j++] = '.';
			}
			else
				(*modify_path)[j++] = path[i];
		}
		for (; j < num_char + 2; j++)
			(*modify_path)[j] = '\0';
	}
	token_ptr = tokenize_str(*modify_path, delim);
	return (token_ptr);
}
