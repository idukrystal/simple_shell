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

typedef struct run_info
{
	char *err_msg;
	int err;
	int end;
	int exit;
}
	run_info;

/* simple.c */
char **un_alias(char **cmd);
void reset(run_info *info);

/* built_in.c */
int  run_alias(char **args, char *name);

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
#endif
