#include "main.h"
/**
 * _getenv - gets address of environment
 * @name: name of environ to be checked
 * Return: address if availble, null otherwise
 */
char **_getenv(const char *name)
{
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while (environ[i][j] == name[j])
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
/**
 * _getindex - gets index of environment
 * @name: name of environ to be checked
 * Return: index if availble, 0 otherwise
 */
int _getindex(const char *name)
{
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while (environ[i][j] == name[j])
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
/**
 * envious - gets pointer to environment
 * @name: name of environ to be checked
 * Return: pointer if availble, NULL otherwise
 */
char *envious(const char *name)
{
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while (environ[i][j] == name[j])
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
