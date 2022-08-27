#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int arg_count(char *p)
{
	int i, counter = 1;
	char *buf = malloc(sizeof(char) *strlen(p));
	for (i = 0; p[i]; ++i)
		buf[i] = p[i];
	char *j = strtok(buf, " ");
	while (strtok(NULL, " "))
		++counter;
	free(buf);
	return(counter);
}
void main(void)
{
	char *p = " HEllo world kabir";
	printf("%d\n", arg_count(p));
}
