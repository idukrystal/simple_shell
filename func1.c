#include "main.h"
void _putchar(char c)
{
	write(1, &c, 1);
}
void printenv(void)
{
	extern char **environ;
	int i, j;

	for (i = 0; environ[i]; ++i)
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
	}
}

int run_built_in(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		return 1;
	}
	if (strcmp(cmd, "env") == 0)
	{
		printenv();
		return 2;
	}
	return 0;
}
/*void main(void)
{
	printenv();
	}*/
