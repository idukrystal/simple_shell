#include "main.h"
char *getpath(char *cmd)
{
	extern char **environ;
	int i, k = _strlen(cmd), l, m;
	char *path = _getenv("PATH"), *buf, *check = NULL, **PATH;

	buf = malloc(sizeof(char) * _strlen(path) + 1);
	buf[_strlen(path)] = '\0';
	_strcpy(path, buf);
	for(i = 0; buf[i] != '/'; ++i)
		buf[i] = ':';
	PATH = extract_args(buf, ':', count_args(buf, ':'));
	for (i = 0; PATH[i] != NULL; ++i)
	{
		if (check)
			free(check);
		check = malloc(sizeof(char) * (_strlen(PATH[i]) + k + 2));
		for (l = 0; PATH[i][l]; ++l)
			check[l] = PATH[i][l];
		check[l++] = '/';
		for (m = 0; cmd[m]; ++m, ++l)
			check[l] = cmd[m];
		check[_strlen(PATH[i]) + k + 1] = '\0';
		if (access(check, X_OK) == 0)
			break;
	}
	if (access(check, X_OK) != 0)
	{
		free(check);
		return (NULL);
	}
	free_args(PATH);
	free(buf);
	return (check);
}
