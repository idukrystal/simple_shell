#include "main.h"
#include "chris.h"

/**
 * printenv - prints env
 * Return: null
 */
void printenv(void)
{
	int i;

	for (i = 0; environ[i]; ++i)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
}

/**
 * is_num - chcks if char is num
 * @s: char
 * Return: 0 if its not a num, 1 otherwise
 */
int is_num(char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * run_built_in - runs built in
 * @cmd: address of command
 * @name: name of command
 * Return: 1 if successful, -1 otherwise
 */
int run_built_in(char **cmd, char *name)
{
	int i;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1] == NULL)
			i = 0;
		else if (is_num(cmd[1]))
			i = (_atoi(cmd[1]));
		else
			_printf("%s: %s: invalid number %s", name, cmd[0], cmd[1]);
		free_args(cmd);
		return (i);
	}
	if (_strcmp(cmd[0], "env") == 0)
	{
		printenv();
		return (1);
	}
	if (_strcmp(cmd[0], "cd") == 0)
	{
		return (ch_dir(cmd, name));
	}
	if (_strcmp(cmd[0], "setenv") == 0)
	{
		if (count(cmd) != 3)

			_printf("usage : setenv VARIABLE VALUE\n");
		else
			_setenv(cmd[1], cmd[2], &i);
		return (1);
	}
	if (_strcmp(cmd[0], "alias") == 0)
	{
		return (run_alias(cmd, name));
	}
	return (-1);
}

/**
 * getvar - gets env variable
 * @var: variable name
 * Return: value of variable
 */
char *getvar(char *var)
{
	char *path  = *_getenv(var);
	char *home = malloc(sizeof(*home) * (_strlen(path) - _strlen(var) - 1));

	int i = 0, j = 0;

	while (path[i] != '=')
		i++;

	while (path[i++] != '\0')
	home[j++] = path[i];
	return (home);
}
