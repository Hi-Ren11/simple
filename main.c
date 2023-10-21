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
	char *line;
	int status = 0;
	int interactive = isatty(STDIN_FILENO);

	(void)argc;
	(void)argv;

	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		line = _getline();

		if (line == NULL)
		{
			if (interactive)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			break;
		}

		if (interactive)
		{
			status = run_command(line, argv[0]);
		}
		else
		{
			status = run_command(line, NULL);
		}

		free(line);
	}
	return (status);
}
