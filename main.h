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
int _strlen(const char *p);
void _strcpy(char *from, char *to);
void printenv(void);
int run_built_in(char *cmd);
void print_prompt(int);
void execute(char *full_path, char **args,char * name, char *cmd);


int _printf(const char *format, ...);
unsigned int validate(const char *, int);
int is_valid(char c);
char *convert_char(void *);
char (*get_conversion_function(char c))(void *);
unsigned int  print_number(int n);
unsigned int  print_u_number(unsigned int n);
int _putchar(char );
unsigned int to_base(unsigned int,char);
int print_address(long long );

#endif /* main_h */
