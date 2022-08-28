#include "main.h"

int count_args(char *str, char del)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0')
	{

		while (str[i]  == del)
		{
			i++;
		}
		if (str[i] != '\0')
		{
			count++;
		}
		while (str[i] != del && str[i] != '\0')
		{
			i++;
	        }
	}
	return (count);
}

char **extract_args(char *input, char del, int arg_count)
{
	char **args = malloc((sizeof(*args) * arg_count) + 1);
	int pos = 0, i = 0, j, k;

	while (input[i] != '\0')
        {

                while (input[i]  == del)
                {
                        i++;
                }
		j = i;
                while (input[j] != del && input[j] != '\0')
                {
                        j++;
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
	args[pos] = NULL;
	return (args);
}

void free_args(char **args)
{
	int i = 0;
	while (args[i] != NULL)
	{
		free(args[i++]);
	}
	free (args);
}
int _strlen(char *p)
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
