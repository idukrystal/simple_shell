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
 * @info: stores execution info
 * Return: 1 if successful, -1 otherwise
 */
int run_built_in(char **cmd, run_info *info)
{
	int i = 0;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		i = run_exit(cmd, info);
		return (i);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		printenv();
		i = 1;
	}
	if (_strcmp(cmd[0], "cd") == 0)
	{
		return (ch_dir(cmd, NULL));
	}
	if (_strcmp(cmd[0], "setenv") == 0)
	{
		if (count(cmd) != 3)
			;
		else
			_setenv(cmd[1], cmd[2], &i);
		return (1);
	}
	if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		_unsetenv(cmd[1], &i);
		return (1);
	}
	if (_strcmp(cmd[0], "alias") == 0)
	{
		i = (run_alias(cmd, NULL));
	}
	return (i);
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
