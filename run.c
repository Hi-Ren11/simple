#include "gmama.h"

/**
 * run_command - runs the command given by the user
 * @shell_ptrs: structure containing all malloced spaces
 * @filename: name of the file being run
 * @envp: environment variable
 * Return: errno value
 */

int run_command(shell_t *shell_ptrs, char *filename, char **envp)
{
	pid_t child_pid;
	char **input_token = shell_ptrs->input_token;
	char **path = shell_ptrs->path_values;
	char *input_org;
	int status = 0;

	if (input_token[0] != NULL)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			input_org = _strdup(input_token[0]);
			input_token[0] = find_pathname(path, input_token[0]);
			if (input_token[0] != NULL)
			{
				if (execve(input_token[0], input_token, envp) == -1)
					perror(filename);
				free(input_token[0]);
			}
			else
			{
				errno = 127;
				p_error(input_org, filename);
			}
			free_shell_t(shell_ptrs);
			free(input_org);
			_exit(errno);
		}
		else
			wait(&status);
	}
	errno = status % 255;
	return (errno);
}

