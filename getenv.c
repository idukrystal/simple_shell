#include "main.h"
char **_getenv(const char *name)
{
	extern char **environ;
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while(environ[i][j] == name[j])
			{
				j++;
			}
			if (environ[i][j] == '=' && name[j] == '\0')
			{
				return (&(environ[i]));
			}
		}
	}
	return (NULL);
}
int _getindex(const char *name)
{
	extern char **environ;
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while(environ[i][j] == name[j])
			{
				j++;
			}
			if (environ[i][j] == '=' && name[j] == '\0')
			{
				return (i);
			}
		}
	}
	return (-1);
}
char *envious(const char *name)
{
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while(environ[i][j] == name[j])
			{
				j++;
			}
			if (environ[i][j] == '=' && name[j] == '\0')
			{
				return (environ[i]);
			}
		}
	}
	return (NULL);
}
