#include "main.h"
#include "chris.h"

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
	        while ((str[i] != del || q)  && str[i] != '\0' )
                {
                    q = still_quoted(str[i++] , q);
                }
	}
	return (count);
}

char **extract_args(char *input, char del, int arg_count)
{
	char **args = malloc(sizeof(*args) * (arg_count + 1));
	int pos = 0, i = 0, j, k;
	char q = '\0';

	args[0] = NULL;
	args[arg_count] = NULL;
	while (input[i] != '\0')
        {

                while (input[i]  == del && input[i]  != '\0')
                {
                        i++;
                }
		j = i;
                while ((input[j] != del || q ) && input[j] != '\0')
                {
                    q = still_quoted(input[j++] , q);
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

void free_args(char **args)
{
	int i = 0;
	while (args[i] != NULL)
	{
		free(args[i++]);
	}
	free (args);
}

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
