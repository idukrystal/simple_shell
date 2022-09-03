#include "main.h"

char *strclone(char *str)
{
	int i = 0;
	char *clone = malloc(sizeof(*str) * (_strlen(str) + 1));
	if (clone == NULL)
		return NULL;
	while(str[i] != '\0')
	{
		clone[i] = str[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}
int _strlen(const char *p)
{
        int i;

        for (i = 0; p[i]; ++i)
                ;
        return (i);
}
void _strcpy(char *from, char *to)
{
        int i;

        for (i = 0; from[i]; ++i)
                to[i] = from[i];
}

char *unquote(char **str)
{
	int len = _strlen(*str), i, j;
	char *tmp;

	if ((*str)[0] != '\'' && (*str)[0] != '\"')
		return *str;
	if ((*str)[len - 1] != '\'' && (*str)[len - 1] != '\"')
		return *str;
	if ((*str)[0] != (*str)[len - 1])
		return *str;

	tmp = malloc(sizeof(*tmp) * (len - 2));

	if (tmp == NULL)
		return *str;

	for (i = 1, j = 0; i < (len - 1); i++, j++)
		tmp[j] = (*str)[i];
	tmp[j] = '\0';

	free(*str);
	*str = tmp;
	return *str;
}
