#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int count_args(char *str, char del);
char **extract_args(char *input, char del, int arg_count);
void free_args(char **args);
