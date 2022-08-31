#include "main.h"
void _alias(void)
{
	char buf[1];
	int fd, length = 0, maxlength = 0, linecount = 0;

	fd = open("~/.bashrc", O_RDONLY);
	if (fd == -1)
		return;
	while(buf[0] != EOF)
	{
		read(fd, buf, 1);
		if (buf[0] == '\n')
		{
			length = 0
			linecount++;
		}
		++length;
		if (length > maxlength)
			maxlength = length;
	}
	++linecount;
	close(fd);
	fd = open("~/.bashrc", O_RDONLY);
	if (fd == -1)
		return;
