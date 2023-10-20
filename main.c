#include "gmama.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: The exit status of the shell
 */

int main(int argc, char **argv)
{
	int status = 0;
	char *line;
	(void) argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = _getline();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			break;
		}

		status = run_command(line, argv[0]);

		free(line);
	}

	return status;
}

