#include "main.h"

/**
 * strclone - makes a copy of a string
 * @str: the string;
 * Return: a copy of str
 */
char *strclone(char *str)
{
	int i = 0;
	char *clone = malloc(sizeof(*str) * (_strlen(str) + 1));

	if (clone == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		clone[i] = str[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

/**
 * _strlen - computes the length of a string
 * @p: the string
 * Return: the length of p
 */
int _strlen(const char *p)
{
	int i;

	for (i = 0; p[i]; ++i)
		;

	return (i);
}

/**
 * _strcpy - copies the content of one string into another
 * @from: string to copy from
 * @to: string to copy to
 */
void _strcpy(char *from, char *to)
{
	int i;

	for (i = 0; from[i]; ++i)
		to[i] = from[i];
}

/**
 * unquote - unquotes a quated string
 * @str: pointer to string
 * Return: modified string
 */
char *unquote(char **str)
{
	int len = _strlen(*str), i, j;
	char *tmp;

	if ((*str)[0] != '\'' && (*str)[0] != '\"')
		return (*str);
	if ((*str)[len - 1] != '\'' && (*str)[len - 1] != '\"')
		return (*str);
	if ((*str)[0] != (*str)[len - 1])
		return (*str);

	tmp = malloc(sizeof(*tmp) * (len - 2));

	if (tmp == NULL)
		return (*str);

	for (i = 1, j = 0; i < (len - 1); i++, j++)
		tmp[j] = (*str)[i];
	tmp[j] = '\0';

	free(*str);
	*str = tmp;
	return (*str);
}

/**
 * _strcat - concatenates two strings
 * @dest: the anpendee string
 *
 * @src: the appended string
 *
 * Return: pointer to modified @dest
 */
char *_strcat(char *dest, char *src)
{
	int o_len = _strlen(dest);
	int n_len = o_len + _strlen(src) + 1;
	dest = _realloc(dest, o_len, n_len);
	int i = 0;

	for (; src[i] != '\0'; i++, o_len++)
	{
		dest[o_len] = src[i];
	}
	dest[n_len] = src[i];
	return (dest);
}
