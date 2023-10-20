#ifndef GMAMA_H
#define GMAMA_H

extern char **environ;

#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * struct shell_env - stores address for pointer to free.
 * @path_values: pointer to path values
 * @input: pointer to buffer that getline creates.
 * @input_token: pointers for input token.
 * @modify_path: pointer to the path after it has been modified
 *
 * Description: provides a storage for all elements that are malloced.
 */
typedef struct shell_env
{
	char **path_values;
	char *input;
	char **input_token;
	char *modify_path;
} shell_t;

/**
 * struct built_in_cmd - struct for different built in commands.
 * @cmd_name: name of the cmd
 * @cmd: function pointer to run the cmd
 *
 * Description: struct for different built in commands in our shell
 */
typedef struct built_in_cmd
{
	char *cmd_name;
	void (*cmd)(shell_t *);
} built_t;

/* main.c */
int run_command(shell_t *, char *, char **);
int run_path(shell_t *, char *);
int check_slash(char *);
int run_build_in(shell_t *, char *);

/* functions */
char *_getenv(const char *);
size_t _strlen(char *);
char *_strdup(char *);
char **tokenize_str(char *, char *);
int _strcmp(char *, char *);
void print_ps1(int);
char *find_pathname(char **, char *);
char *make_pathname(char *, char *);
char **get_path(char **);
void free_shell_t(shell_t *);
void p_error(char *, char *);
void my_exit(shell_t *);
void print_env(shell_t *);
char *_strtok(char *, const char *);
ssize_t getline(char **, size_t *, FILE *);

#endif /* GMAMA_H */
