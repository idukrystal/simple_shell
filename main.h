#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>

char *_getenv(const char *name);
int count_args(char *str, char del);
char **extract_args(char *input, char del, int arg_count);
void free_args(char **args);
char *getpath(char *cmd);

#endif /* main_h */
