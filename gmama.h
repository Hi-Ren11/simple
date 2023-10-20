#ifndef GMAMA_H
#define GMAMA_H

extern char **environ;

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

char *_getline(void);
int run_command(char *command, char *filename);
void my_exit(char **input_token);
char **tokenize_input(char *str, char *delim);
char **tokenize_arguments(char *command_line);

/* Strings */
char *_strdup(char *s);
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strtok(char *str, const char *delim);

#endif /* GMAMA_H */
