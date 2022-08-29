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
void _setenv(char *env, int *eflag)
{
	int i, j;
	int c = 0;
	char **newenv;
	for (i = 0; environ[i]; ++i)
		;
	newenv = malloc(sizeof(*environ) * i + 2);
	newenv[i] = malloc(sizeof(char) * _strlen(env) + 1);
	for (j = 0; env[j]; ++j)
		newenv[i][j] = env[j];
	newenv[i][j] = '\0';
	newenv[i + 1] = NULL;
	for (i = 0; environ[i]; ++i)
	{
		printf("%d\n", c++);
		newenv[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		for (j = 0; environ[i][j]; ++j)
			newenv[i][j] = environ[i][j];
		newenv[i][j] = '\0';
	}
	*eflag = 1;
	environ = newenv;
}
void main(void)
{
	int m;
	_setenv("hello", &m);
	printenv();
}
