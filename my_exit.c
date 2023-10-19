#include "gmama.h"

/**
 * my_exit - Exit the shell
 * @input_token: The array of tokens
 *
 * This function exits the shell, taking an optional exit status from the
 * second token of the input tokens array.
 */
void my_exit(char **input_token)
{
	unsigned int i;
	char *exit_str = input_token[1];

	if (exit_str != NULL || input_token == NULL)
	{
		errno = 0;
		for (i = 0; exit_str[i] != '\0'; i++)
			errno = errno * 10 + (exit_str[i] - '0');
	}
	if (input_token)
	{
		free(input_token);
	}

	if (errno > 255)
	{
		errno %= 256;
	}
	exit(errno);
}
