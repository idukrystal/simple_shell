#include "main.h"

ssize_t  _getline (char **line, size_t *size)
{
	char tmp = 'z';
	static char buff[BUFFSIZE];
	static int no;
	static int cursor;
	int i = 0, j;

	if (line == NULL)
		return (-1);
	if (*line == NULL)
	{
		*size = 128;
		*line = malloc(sizeof(**line) * (*size));
	}
	while (1)
	{
		if (no == 0)
		{
			j = read(STDIN_FILENO, buff, BUFFSIZE);
			if (j == 0)
				return (-1);
		        
			no = j;
			cursor = 0;
		}
		while ((*line)[i - 1]  != '\n' && cursor < no)
		{
			if (i >= *size)
			{
				*line = _realloc(*line, *size, *size + 128);
				*size += 128;
			}
			(*line)[i++] = buff[cursor++];
	        }
		if ((*line)[i - 1] == '\n')
		{

			(*line)[i] = '\0';
			break;
		}
		no = 0;
	}
	return i;
}
/*int main()
{
	size_t  i = 3;
	char *str = NULL;
	_getline(&str, &i);
	printf("%s\n", str);
	_getline(&str, &i);
	printf("%s\n", str);
	free(str);
}

*/
