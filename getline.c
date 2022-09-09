#include "main.h"
#include "chris.h"

/**
 * _getline - gets line
 * @line: pointer to contain read string
 * @size: numberof chars printed
 * @fd: fild descriptor of source
 * Return: no of chars read. 0 if empty, -1 if failed
 */
ssize_t  _getline(char **line, size_t *size, int fd)
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
	return (i);
}

void print_alias_rec(alias_t *list,char  *name)
{
	if (list == NULL)
		return;
	print_alias_rec(list->next, name);
	print_alias(list, 1, name);
}
