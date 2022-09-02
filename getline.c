#include "main.h"
#include "chris.h"

ssize_t  _getline (char **line, size_t *size, int fd)
{
	static char buff[BUFFSIZE];
	static int no, cursor;
	size_t i = 0, j;

	if (line == NULL)
		return (-1);
	if (*line == NULL)
	{;
		*line = _malloc(sizeof(**line) * (*size = 128));
	}
	while (1)
	{
		if (no == 0)
		{
			j = read(fd, buff, BUFFSIZE);
			if (j == 0)
				return (-1);
			no = j;
			cursor = 0;
		}
		while (1)
		{
			if (i >= *size)
			{
				*line = _realloc(*line, *size, *size + 128);
				*size += 128;
			}
			(*line)[i] = buff[cursor++];
			if ((*line)[i++]  == '\n' || !(cursor < no))
				break;
	        }
		no = (no == cursor) ? 0 : no;
		if ((*line)[i - 1] == '\n')
		{

			(*line)[i] = '\0';
			break;
		}
	}
	return i;
}
/*
int main()
{
	size_t  i = 3;
	char *str = NULL;
	_getline(&str, &i, STDIN_FILENO);
	printf("%s\n", str);
	_getline(&str, &i, STDIN_FILENO);
	printf("%s\n", str);
	free(str);
	}*/

