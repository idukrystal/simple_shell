#include <stdio.h>
#include <stdlib.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = -1, j;

	while (environ[++i] != NULL)
	{
		j = 0;
		if (environ[i][j] == name[j])
		{
			while(environ[i][j] == name[j++])
			{
			}
			if (environ[i][--j] == '=' && name[j] == '\0')
			{
				return (environ[i]);
			}
		}
	}
	return ("null");
}
