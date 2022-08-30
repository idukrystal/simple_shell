#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>

char **_getenv(const char *name);
int count_args(char *str, char del);
char **extract_args(char *input, char del, int arg_count);
void free_args(char **args);
char *getpath(char *cmd);
int _strlen(const char *p);
void _strcpy(char *from, char *to);
void printenv(void);
int run_built_in(char **cmd, char *);
void print_prompt(int);
void execute(char **args,char * name);
int to_int(char *s, int start, int stop);
int _strcmp(char *dest, char *src);
int _printf(const char *format, ...);
unsigned int validate(const char *, int);
int is_valid(char c);
char *convert_char(void *);
int _atoi(char *s);
char (*get_conversion_function(char c))(void *);
unsigned int  print_number(int n);
unsigned int  print_u_number(unsigned int n);
int _putchar(char );
unsigned int to_base(unsigned int,char);
char *getvar(char *var);
void _setenv(char *env, char *vne, int *eflag);
int _getindex(const char *name);
void _unsetenv(char *env, int *eflag);
int count(char **args);
void print_exec_error(char *cmd, char *name, int  err);
int ch_dir(char **cmd, char *);

#endif /* main_h */
