int count_args(char *str)
{
	int i = 0;
	char c;
	int count = 0;

	while (str[i] != '\0')
	{

		while (str[i]  == ' ')
		{
			i++;
		}
		if (str[i] != '\0')
		{
			count++;
		}
		while (str[i] != ' ' && str[i] != '\0')
		{
			i++;
	        }
	}
	return (count);
}

char **extract_args(char *input, int arg_count)
{
	char **args = malloc((sizeof(*args) * arg_count) + 1);
	int pos = 0, i = 0, j, k;

	args[arg_count + 1] = NULL;
	while (input[i] != '\0')
        {

                while (input[i]  == ' ')
                {
                        i++;
                }
		j = i;
                while (input[j] != ' ' && input[j] != '\0')
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
	return (args);
}

void free_args(char **args)
{
	int i = 0;
	while (args[i] != NULL)
		free(arg[i++]);
	free (args);
}
