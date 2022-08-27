#include "main.h"

int main(int ac, char **av)
{
        char **cmd = malloc(sizeof(*cmd) * 1);
	char **args;
	size_t max = 100;
        extern char **environ;
	int w = ac;
	pid_t pid;
	int is_atty = isatty(STDIN_FILENO);

	*cmd = NULL;
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
		args = extract_args(*cmd, ' ', count_args(*cmd, ' '));
		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, environ);
			execve(getpath(args[0]), args, environ);
			printf("%s: %s: not found\n", av[0], cmd[0]);
			break;
		}
		else
			wait(&w);
	}

	if (*cmd != NULL)
		free(*cmd);

	if (args != NULL)
		free_args(args);
	free(cmd);
	return 0;
}
