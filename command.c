#include "gmama.h"

/**
 * run_command - Execute a command.
 * @command_line: The full command line.
 * @filename: The name of the shell or program executing the command.
 *
 * Return: The exit status of the command.
 */
int run_command(char *command_line, char *filename) {
    char **arguments = tokenize_arguments(command_line);

    if (!arguments) {
        /* Handle error or display a message */
        return -1;
    }

    pid_t child_pid;
    int status = 0;

    if (arguments[0] != NULL) {
        child_pid = fork();
        if (child_pid == 0) {
            if (execve(arguments[0], arguments, environ) == -1) {
                if (filename) {
                    perror(filename); // Display the program name (path) on error
                }
                _exit(127);
            }
        } else if (child_pid == -1) {
            if (filename) {
                perror(filename); // Display the program name (path) on error
            }
        } else {
            waitpid(child_pid, &status, 0);
        }
    }

    /* Free the memory allocated for arguments */
    for (int i = 0; arguments[i] != NULL; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return WEXITSTATUS(status);
}

