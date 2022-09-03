#include "main.h"
#include <stdlib.h>

/**
 * _realloc -  reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *clone, *relloc;
	unsigned int i;

	if (ptr != NULL)
	clone = ptr;
	else
	{ return (malloc(new_size)); }
	if (new_size == old_size)
	return (ptr);
	if (new_size == 0 && ptr != NULL)
	{ free(ptr);
	return (0); }
	relloc = malloc(new_size);
	if (relloc == NULL)
	return (0);
	for (i = 0; i < old_size &&  i < new_size; i++)
	{
		*(relloc + i) = clone[i];
	}
	for (; i < new_size; i++)
	{
		*(relloc + i) = '\0';
	}
	free(ptr);
	return (relloc);
}

/**
 * _malloc - mallocs
 * @size: size of space to malloc
 * Return: void
 */
void *_malloc(unsigned long size)
{
	char  *new = malloc(size);
	int i;

	if (new == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		*(new + i) = '\0';
	}
	return (new);
}
