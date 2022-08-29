#include "main.h"
void setenv(char *env, int *eflag)
{
	int i, j;
	char **newenv;
	for (i = 0; environ[i]; ++i)
		;
	newenv = malloc(sizeof(*environ) * i + 2);
	newenv[i] = malloc(sizeof(char) * _strlen(env) + 1);
	for (j = 0; env[j]; ++i)
		newenv[i][j] = env[j];
	newenv[i][j] = '\0';
	newenv[i + 1] = NULL;
	for (i = 0; environ[i]; ++i)
	{
		newenv[i] = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		for (j = 0; environ[i][j]; ++j)
			newenv[i][j] = environ[i][j];
		newenv[i][j] = '\0';
	}
	eflag = 1;
	environ = newenv;
}
