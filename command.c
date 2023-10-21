#include "gmama.h"

/**
 * run_command - Execute a command
 * @command: The command to execute
 * @filename: The program name for error display
 *
 * Return: The exit status of the executed command
 */

int run_command(char *command, char *filename)
{
	pid_t child_pid;
	int status = 0;

	if (_strcmp(command, "exit") == 0)
	{
		my_exit(NULL);
	}

	if (command != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execlp(command, command, (char *)NULL) == -1)
			{
				if (filename)
				{
					perror(filename);
				}
				_exit(127);
			}
		}
		else if (child_pid == -1)
		{
			if (filename)
			{
				perror(filename);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	return (status);
}
