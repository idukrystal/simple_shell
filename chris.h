#ifndef CHRIS_H
#define CHRIS_H

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

/* built_in.c */
int  run_alias(char **args, char *name);
int run_exit(char **cmd, run_info *info);

/* alias.c */
int add_alias(char *name, char *value);
alias_t *get_alias(char *name);
void  free_alias(alias_t *);
alias_t *parse_alias(char *str);
void print_alias(alias_t *list, int, char *);

/* string_function.c */
char *strclone(char *str);
char *unquote(char **str);

/* alloc.c */
void *_malloc(unsigned long);

char still_quoted(char new_q, char old_q);

/* system.c */
alias_t **alias();

int run_built_in(char **cmd, run_info  *);
int is_num(char *s);

int file_stat(const char *path);
int is_dir_name(const char *path);
#endif
