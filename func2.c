#include "main.h"

int count(char **args)
{
	int i = 0;

	while(args[i] != NULL)
		i++;
	return (i);
}
