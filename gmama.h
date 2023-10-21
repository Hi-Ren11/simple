#ifndef GMAMA_H
#define GMAMA_H

extern char **environ;

/* header files */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* function prototype */
char *_getline();
char *_getline(void);
int run_command(char *command, char *filename);
void my_exit(char **input_token);

/* strings */
char *_strdup(char *s);
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);

#endif /* GMAMA_H */
