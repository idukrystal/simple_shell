#include "main.h"
#include "chris.h"

/**
 * count_args - computes no of seprable inouts in a string
 * @str: the string
 * @del: delimeter character
 * Return: count
 */
int count_args(char *str, char del)
{
	int i = 0;
	char q = '\0';
	int count = 0;

	while (str[i] != '\0')
	{

		while (str[i]  == del && str[i] != '\0')
		{
			i++;
		}
		if (str[i] != '\0')
		{
			count++;
		}
		while ((str[i] != del || q)  && str[i] != '\0')
		{
			q = still_quoted(str[i++], q);
		}
	}
	return (count);
}

/**
 * extract_args - breaks a string into an array of strings
 * @input: the string
 * @del: separating character
 * @arg_count: expected no of array
 * Return: array of string
 */
char **extract_args(char *input, char del, int arg_count)
{
	char **args = malloc(sizeof(*args) * (arg_count + 1));
	int pos = 0, i = 0, j, k;
	char q = '\0';
		printf("%c ---- %p\n", del,args);
	args[0] = NULL;
	args[arg_count] = NULL;
	while (input[i] != '\0')
	{
		while (input[i]  == del && input[i]  != '\0')
		{
			i++;
		}
		j = i;
		while ((input[j] != del || q) && input[j] != '\0')
		{
			q = still_quoted(input[j++], q);
		}
		if (j != i)
		{
			args[pos] = malloc((sizeof(**args) * (j - i)) + 1);
			for (k = i; k < j; k++)
			{
				args[pos][k - i] = input[k];
			}
			args[pos++][k - i] = '\0';
		}
		i = j;
	}
	return (args);
}

/**
 * free_args - frees an array of strings
 * @args: the array
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i++]);
	}
	free(args);
}

/**
 * still_quoted - detemines if cursor is withen a quated string when reading
 * @new_q: the new quoate character
 * @old_q: old quote character
 * Return: quated character
 */
char still_quoted(char new_q, char old_q)
{
	if (new_q != '\'' && new_q != '\"')
		return (old_q);
	if (old_q == '\0')
		return (new_q);
	if (old_q == new_q)
		return  ('\0');
	return (old_q);
}
