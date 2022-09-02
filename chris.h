#ifndef CHRIS_H
#define CHRIS_H

typedef struct alias_s
{
	char *name;
	char *val;
	struct alias_s *next;
}
alias_t;

extern alias_t *alias;

/* simple.c */
char *un_alias(char *cmd);

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

void *_malloc (unsigned long);

#endif
