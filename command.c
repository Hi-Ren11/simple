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
	char *command = strtok(command_line, " \t\n");

	if (command == NULL)
		return (0);
	if (_strcmp(command, "exit") == 0)
	{
		my_exit(NULL);
	}
	if (command != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			char *envp[] = {NULL};

			if (execve(command, &command, envp) == -1)
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
	}
	return (status);
}
