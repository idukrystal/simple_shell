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
void main(void)
{
	printenv();
}
