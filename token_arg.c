#include "gmama.h"

/**
 * tokenize_arguments - Tokenize command arguments.
 * @command_line: The command line to be tokenized.
 *
 * Return: An array of tokens (strings) or NULL on failure.
 */

char **tokenize_arguments(char *command_line)
{
	char *arg = _strtok(NULL, "");
	char *command = strtok(command_line, " \t\n");
	char **arguments = malloc(sizeof(char *) * 2);

	if (command == NULL)
		return (NULL);

	if (!arguments)
		return (NULL);

	arguments[0] = _strdup(command);
	arguments[1] = arg ? _strdup(arg) : NULL;

	return (arguments);
}
