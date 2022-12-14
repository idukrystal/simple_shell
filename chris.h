#ifndef CHRIS_H
#define CHRIS_H
#include <fcntl.h>

/**
 * struct alias_s - represents a single alias
 * @name: name of of alias;
 * @val: value of alias
 * @next: for use in a linked list
 */
typedef struct alias_s
{
	char *name;
	char *val;
	struct alias_s *next;
}
alias_t;

/**
 * struct run_info - runnable
 * @err_msg: stuff giea
 * @err: gih kbkw
 * @end: hhahhana nanna
 * @exit: hhqhhwhw
 */
typedef struct run_info
{
	char *err_msg;
	int err;
	int end;
	int exit;
}
	run_info;

/* simple.c */
void execute(char **args, run_info *);
char **un_alias(char **cmd);
void reset(run_info *info);
void kabir(int p, int is_atty);

/* built_in.c */
int  run_alias(char **args, char *name);
int run_exit(char **cmd, run_info *info);

/* alias.c */
int add_alias(char *name, char *value);
alias_t *get_alias(char *name);
void  free_alias(alias_t *, int mode);
alias_t *parse_alias(char *str);
void print_alias(alias_t *list, int, char *);

/* string_function.c */
char *strclone(char *str);
char *unquote(char **str);
char *_strcat(char *dest, char *src);

/* alloc.c */
void *_malloc(unsigned long);

char still_quoted(char new_q, char old_q);

/* system.c */
alias_t **alias();
void set_mode(int, char *file, int *fd, int *is_file, int *is_atty, char *);
void save_exit(char *, int is_file, int fd);

int run_built_in(char **cmd, run_info  *);
int is_num(char *s);

int file_stat(const char *path);
int is_dir_name(const char *path);
char *get_valid_path(int status, char **args, run_info *info, int *is_path);

void print_alias_rec(alias_t *, char *);
#endif
