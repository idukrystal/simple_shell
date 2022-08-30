#include "main.h"
extern char **environ;
int  _putchar(char c)
{
	return (write(1, &c, 1));
}
void printenv(void)
{
	int i;

	for (i = 0; environ[i]; ++i)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
}
int _strlen(const char *p)
{
	int i;

	for (i = 0; p[i]; ++i)
		;
	return (i);
}
void _setenv(char *env, char *vne, int *eflag)
{
	int i, j, k;
	char **newenv;

	if (getenv(env) != NULL)
		return;
	for (i = 0; environ[i]; ++i)
		;
	newenv = malloc(sizeof(*environ) * i + 2);
	newenv[i] = malloc(sizeof(char) * (_strlen(env) + _strlen(vne) + 1));
	for (j = 0; env[j]; ++j)
		newenv[i][j] = env[j];
	newenv[i][j++] = '=';
	for (k = 0; vne[k]; ++k, ++j)
		newenv[i][j] = vne[k];
	newenv[i][j] = '\0';
	newenv[i + 1] = NULL;
	for (i = 0; environ[i]; ++i)
	{
		newenv[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		for (j = 0; environ[i][j]; ++j)
			newenv[i][j] = environ[i][j];
		newenv[i][j] = '\0';
	}
	/*
	if (*eflag == 1)
		free_args(environ);
		*/
	/* remember to add error messages*/
	*eflag = 1;
	environ = newenv;
}
void _unsetenv(char *env, int *eflag)
{
	int i, j, k, index;
	char **newenv;

	index = _getindex(env);
	if (index == -1)
		return;
	for (i = 0; environ[i]; ++i)
		;
	newenv = malloc(sizeof(*environ) * i);
	newenv[i - 1] = NULL;
	for (i = 0, j = 0; environ[j]; ++i, ++j)
	{
		if (j == index)
			++j;
		newenv[i] = malloc(sizeof(char) * _strlen(environ[j]) + 1);
		for (k = 0; environ[j][k]; ++k)
			newenv[i][k] = environ[j][k];
		newenv[i][k] = '\0';
	}
	/*
	if (*eflag == 1)
		free_args(environ);
		*/
	environ = newenv;
	/*error messages*/
}
void main(void)
{
	int m = 0;
	_unsetenv("TERM", &m);
	printenv();
}
