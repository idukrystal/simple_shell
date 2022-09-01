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
