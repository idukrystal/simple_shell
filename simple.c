#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
        char **cmd = malloc(sizeof(*cmd) * 2);
	size_t max = 100;
        extern char **environ;
	int w = ac;
	pid_t pid;
	int is_atty = isatty(STDIN_FILENO);

	while(1)
	{
		if (is_atty)
			printf("($) ");
		w = getline(cmd, &max, stdin);
		if (w == -1)
		{
			if (is_atty)
				putchar('\n');
			break;
		}
		if (w == 1)
			continue;
		(*cmd)[w - 1] = '\0';//((*cmd)[w - 1] == '\n') ? '\0' : (*cmd)[w-1];
		if(strcmp(*cmd,"exit") == 0)
			break;
		pid = fork();
		if (pid == 0)
		{
			execve(cmd[0], cmd, environ);
			printf("%s: %s: not found\n", av[0], cmd[0]);
			break;
		}
		else
			wait(&w);
	}
	free(cmd);
	return 0;
}
