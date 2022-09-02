#include "main.h"
/**
 * count - counts
 * @args: string
 * Return: number of count
 */
int count(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	return (i);
}
