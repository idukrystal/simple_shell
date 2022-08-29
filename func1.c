#include "main.h"
int  _putchar(char c)
{
	return (write(1, &c, 1));
}
void printenv(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i]; ++i)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
}

int is_num(char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return 0;
	}
	return 1;
}

int run_built_in(char **cmd,char *name)
{
	char *str = NULL;

	if (strcmp(cmd[0], "exit") == 0)
	{
		if (cmd [1] == NULL)
			return (0);
		if (is_num(cmd[1]))
			return (atoi(cmd[1]));
		_printf("%s: %s: invalid number %s", name,cmd[0], cmd[1]);
		return 1;
   	}
	if (strcmp(cmd[0], "env") == 0)
	{
		printenv();
		return 1;
	}
	if (strcmp(cmd[0], "cd") == 0)
	{
	        if (cmd[1] == NULL)
		{
			str = getvar("HOME");
			chdir(str);
		}
		else
			chdir(cmd[1]);
		if (str != NULL)
			free(str);
		return 1;
	}
	return -1;
}

char *getvar(char *var)
{
	char *path  = _getenv(var);
	char *home = malloc(sizeof(*home) * (_strlen(path) - _strlen(var) - 1));

	int i = 0, j = 0;
	while (path[i] != '=')
		i++;

	while (path[i++] != '\0')
	home[j++] = path[i];
	return (home);
}
/*void main(void)
{
	printenv();
	}*/
