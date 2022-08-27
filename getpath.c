#include "main.h"
char *getpath(char *cmd)
{
	extern char **environ;
	int i, j, k, l, m;
	char *path = _getenv("PATH"), *buf, *check, **PATH;

	for (k = 0; cmd[k]; ++k)
		;
	for (i = 0; path[i]; ++i)
		;
	buf = malloc(sizeof(char) * i + 1);
	buf[i] = '\0';
	for(i = 0; path[i]; ++i)
		buf[i] = path[i];
	for(i = 0; buf[i] != '/'; ++i)
		buf[i] = ':';
	PATH = extract_args(buf, ':', count_args(buf, ':'));
	for (i = 0; PATH[i] != NULL; ++i)
	{
		for (j = 0; PATH[i][j]; ++j)
			;
		check = malloc(sizeof(char) * (j + k + 2));
		for (l = 0; PATH[i][l]; ++l)
			check[l] = PATH[i][l];
		check[l++] = '/';
		for (m = 0; cmd[m]; ++m, ++l)
			check[l] = cmd[m];
		check[j+ k + 1] = '\0';
		printf("%s\n", check);
		/*if (access(check, X_OK) == 0)
			break;*/
	}
	free_args(PATH);
	free(buf);
	return (check);
}
void main(void)
{
	char *p = getpath("ls");
	free(p);
}
