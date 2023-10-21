#include "gmama.h"

/**
 * _getline - Read a line of input from stdin
 *
 * Return: The input line (including '\0' termination) or NULL on failure
 */

char *_getline(void)
{
	ssize_t ReadRV;
	char *line = NULL;
	size_t len = 0;

	ReadRV = getline(&line, &len, stdin);

	if (ReadRV == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[ReadRV - 1] == '\n')
	{
		line[ReadRV - 1] = '\0';
	}
	return (line);
}
