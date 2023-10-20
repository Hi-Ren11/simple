#include "gmama.h"

/**
 * run_command - Execute a given command.
 * @command_line: The command line to execute.
 * @filename: The name of the shell program (used for error reporting).
 *
 * Return: The exit status of the executed command.
 */
int run_command(char *command_line, char *filename)
{
	pid_t child_pid;
	int status = 0;
	int i;
	char **arguments = tokenize_arguments(command_line);

	if (!arguments)
		return (-1);

	if (arguments[0] != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(arguments[0], arguments, environ) == -1)
			{
				if (filename)
					perror(filename);
				_exit(127);
			}
		}
		else if (child_pid == -1)
		{
			if (filename)
				perror(filename);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
		for (i = 0; arguments[i] != NULL; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
	}
	return (status);
}
