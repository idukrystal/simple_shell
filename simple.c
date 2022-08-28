#include "main.h"

int main(int ac, char **av)
{
	char *cmd = NULL;
	char **args = NULL;
	size_t max = 100;
	char *full_path;
        extern char **environ;
	int w = ac;
	pid_t pid;
	int is_atty = isatty(STDIN_FILENO);

	while(1)
	{
		if (is_atty)
			printf("($) ");
		w = getline(&cmd, &max, stdin);
		if (w == -1)
		{
			if (is_atty)
				putchar('\n');
			break;
		}
		if (w == 1)
			continue;
		cmd[w - 1] = '\0';
		if(strcmp(cmd,"exit") == 0)
			break;
		args = extract_args(cmd, ' ', count_args(cmd, ' '));
		if (args[0][0] == '.' || args[0][0] == '/' || args[0][0] == '~')
			full_path = args[0];
		else
			full_path = getpath(args[0]);
		if (full_path == NULL)
		{
			printf("%s: %s: not found\n", av[0], cmd);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			execve(full_path, args, environ);
			printf("%s: %s: no such file or  directory\n", av[0], cmd);
			break;
		}
		else
		{
			wait(&w);
			if (args != NULL)
				free_args(args);
		}
	}
	if (cmd != NULL)
		free(cmd);

	return 0;
}
