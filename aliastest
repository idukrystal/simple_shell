#include "main.h"
void _alias(void)
{
	char buf[1];
	int fd, length = 0, readlength = 0;

	fd = open("~/.bashrc", O_RDONLY);
	if (fd == -1)
		return;
	while (1)
	{
		read(fd, buf, 1);
		if (buf[0] == '\n' || buf[0] == EOF)
		{
			kabir(length, readlength);
			readlength += length + 1;
			length = 0;
			if (buf[0] == EOF)
				break;
			continue;
		}
		length++;
	}
	close(fd);
}
