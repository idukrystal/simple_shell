#include "main.h"
/**
 * _putchar - puts char
 * @c: char
 * Return: 1
 */
int  _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _setenv - sets environ variable
 * @env: variable
 * @vne: value
 * @eflag: malloc checker
 * Return: nill
 */
void _setenv(char *env, char *vne, int *eflag)
{
	int i, j, k;
	char **newenv;
	char **old_val = _getenv(env);
	char *new_val;

	new_val = malloc(sizeof(char) * (_strlen(env) + _strlen(vne) + 2));
	for (j = 0; env[j]; ++j)
		new_val[j]  = env[j];
	new_val[j++] = '=';
	for (k = 0; vne[k]; ++k, ++j)
		new_val[j] = vne[k];
	new_val[j] = '\0';

	if (old_val != NULL)
	{
		free(*old_val);
		*old_val = new_val;
		return;
	}
	for (i = 0; environ[i]; ++i)
		;
	newenv = malloc(sizeof(*environ) * (i + 2));
	newenv[i] = new_val;
	newenv[i + 1] = NULL;
	for (i = 0; environ[i]; ++i)
	{
		newenv[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		for (j = 0; environ[i][j]; ++j)
			newenv[i][j] = environ[i][j];
		newenv[i][j] = '\0';
	}
	if (*eflag == 1)
		free_args(environ);
	/* remember to add error messages*/
	*eflag = 1;
	environ = newenv;
}
/**
 * _unsetenv - unsets env
 * @env: env variable name
 * @eflag: malloc checker
 * Return: nul
 */
void _unsetenv(char *env, int *eflag)
{
	int i, j, k, index, end;
	char **newenv;

	index = _getindex(env);
	if (index == -1)
		return;
	for (i = 0; environ[i]; ++i)
		;
	end = i - 1;
	newenv = malloc(sizeof(*environ) * i);
	newenv[end] = NULL;
	for (i = 0, j = 0; environ[j]; ++i, ++j)
	{
		if (j == index)
			++j;
		if (j >= end)
			break;
		newenv[i] = malloc(sizeof(char) * _strlen(environ[j]) + 1);
		for (k = 0; environ[j][k]; ++k)
			newenv[i][k] = environ[j][k];
		newenv[i][k] = '\0';
	}
	if (*eflag == 1)
		free_args(environ);
	environ = newenv;
	/* error messages */
}
