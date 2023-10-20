#include "gmama.h"

/**
 * run_path - runs the command specified by the pathname
 * @shell_ptrs: structure containing all malloced memory
 * @filename: filename of the file
 * Return: exit status of the executed command
 */

int run_path(shell_t *shell_ptrs, char *filename)
{
	pid_t child_pid;
	int status = 0;
	char **input_token = shell_ptrs->input_token;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(input_token[0], input_token, environ) == -1)
			perror(filename);
		free_shell_t(shell_ptrs);
		_exit(errno);
	}
	else if (child_pid == -1)
	{
		perror("Fork failed");
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	errno = (status);

	return (errno);
}

