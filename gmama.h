#ifndef GMAMA_H
#define GMAMA_H

extern char **environ;

/* header files */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* function prototype */
char *_getline();

/* strings */
char *_strdup(char *s);
int _strcmp(char *str1, char *str2);
size_t _strlen(char *str);

#endif
