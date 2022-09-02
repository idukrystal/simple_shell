#include "main.h"
extern char **environ;
/**
 * _pow - finds exponent of base
 * @base: number to be exp
 * @exp: exp number
 * Return: result of exp
 */
unsigned int _pow(int base, unsigned int exp)
{
	int result = base;

	while (exp > 1)
	{
		result *= base;
		--exp;
	}
	if (exp == 0)
		return (1);
	return (result);
}
/**
 * itoa - integer top string
 * @a: int to be converted
 * Return: pointer to string
 */
char *itoa(int a)
{
	int i = a, count = 0;
	char *p;

	while (i)
	{
		i = i / 10;
		count++;
	}
	p = malloc(count + 1);
	p[count] = '\0';
	count--;
	for (i = 0; count != -1; i++, count--)
	{
		p[i] = ((a / _pow(10, count)) % 10) + 48;
	}
	return (p);
}
/**
 * restruct - expands command
 * @cmd: address of command string
 * @i: index of expansion
 * @j: index of expansion end
 * @expand: expanson value
 * Return: nill
 */
void restruct(char **cmd, int i, int j, char *expand)
{
	int m, n, o;
	char  *new;

	new = malloc(1024);
	for (m = 0, n = 0; (*cmd)[n]; ++m, ++n)
	{
		if (m == i)
		{
			if (envious(expand) != NULL)
			{
				expand = envious(expand);
				for (o = 0; expand[o] != '='; ++o)
					;
				o++;
				for (; expand[o]; ++o, ++m)
					new[m] = expand[o];
				n = j + 1;
			}
			else
			{
				for (o = 0; expand[o]; ++o, ++m)
					new[m] = expand[o];
				n = j + 1;
			}
		}
		if ((*cmd)[n] == '\0')
			break;
		new[m] = (*cmd)[n];
	}
	new[m] = '\0';
	free(*cmd);
	*cmd = new;
}
/**
 * dollar - calls restruct when possible
 * @cmd: address of command
 * @exitstatus: pointer to exitstatus
 * Return: nill
 */
void dollar(char **cmd, int *exitstatus)
{
	int i, j, k = 0;
	char *expand, *p;

	for (i = 0, j = 1; (*cmd)[j]; ++i, ++j)
	{
		if ((*cmd)[i] == '$')
		{
			if ((*cmd)[j] == '$')
			{
				expand = itoa(getpid());
				restruct(cmd, i, j, expand);
				free(expand);
			}
			else if ((*cmd)[j] == '?')
			{
				expand = itoa(*exitstatus);
				restruct(cmd, i, j, expand);
				free(expand);
			}
			else
			{
				expand = malloc(sizeof(char) * 100);
				while (k < 100)
					expand[k++] = '\0';
				for (k = 0; envious(expand) == NULL; ++k)
				{
					if ((*cmd)[i + k + 1] == '$' || (*cmd)[i + k + 1] == '\0')
						break;
					expand[k] = (*cmd)[i + k + 1];
				}
				if (envious(expand) != NULL)
					restruct(cmd, i, i + k, expand);
				free(expand);
			}
		}
	}
}
/*
void main(void)
{
	char *cmd = malloc(10);
	int i = 12;
	cmd[0] = '$';
	cmd[1] = '?';
	cmd[2] = '$';
	cmd[3] = '$';
	cmd[4] = '$';
	cmd[5] = '\0';
	dollar(&cmd, &i);
	printf("%s\n", cmd);
	free(cmd);
	}
	*/
