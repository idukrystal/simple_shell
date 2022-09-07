#ifndef MAIN_H
#define MAIN_H
#define BUFFSIZE 5
#define alias_location "./hsh_alias"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdarg.h>

extern char **environ;

char **_getenv(const char *name);
int count_args(const char *str, char del);
char **extract_args(const char *input, char del, int arg_count);
void free_args(char **args);
char *getpath(const char *cmd);
int _strlen(const char *p);
void _strcpy(char *from, char *to);
void printenv(void);
void print_prompt(int);
int to_int(char *s, int start, int stop);
int _strcmp(const char *dest, const char *src);
int _printf(const char *format, ...);
unsigned int validate(const char *, int);
int is_valid(char c);
char *convert_char(void *);
int _atoi(char *s);
char (*get_conversion_function(char c))(void *);
unsigned int  print_number(int n);
unsigned int  print_u_number(unsigned int n);
int _putchar(char c);
unsigned int to_base(unsigned int, char);
char *getvar(char *var);
void _setenv(char *env, char *vne, int *eflag);
int _getindex(const char *name);
void _unsetenv(char *env, int *eflag);
int count(char **args);
void print_exec_error(char *cmd, char *name, int  err);
int ch_dir(char **cmd, char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void dollar(char **cmd, int *exitstatus);
void restruct(char **cmd, int i, int j, char *expand);
unsigned int _pow(int base, unsigned int exp);
char *itoa(int a);
ssize_t  _getline(char **line, size_t *size, int fd);
char *envious(const char *name);

#endif /* main_h */
