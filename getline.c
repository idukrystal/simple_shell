#include "main.h"
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char buf[INT_MAX];
	int i, flag = 0, count = 0;

	while (flag == 0)
	{
		if (read(buf, 1, INT_MAX, stream) == -1)
			return (-1);
		for (i = 0; i < INT_MAX; ++i)
		{
			if (buf[i] == '\n' || buf[i] == EOF)
			{
				flag = 1;
				break;
			}
		}
	}
