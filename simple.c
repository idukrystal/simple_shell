#include "main.h"

int main(int ac, char **av)
{
	char *cmd = NULL, *full_path, **args = NULL;
	size_t max = 100;
	int errno = 0, w = ac, is_atty = isatty(STDIN_FILENO);

	while(1)
	{
		print_prompt(is_atty);
		w = getline(&cmd, &max, stdin);
		if (w == -1)
		{
			if (is_atty)
				_putchar('\n');
			break;
		}
		if (w == 1)
			continue;
		cmd[w - 1] = (cmd[w - 1] == '\n') ? '\0' : cmd[w - 1];
		args = extract_args(cmd, ' ', count_args(cmd, ' '));
		errno = (run_built_in(args, av[0]));
                if (errno != -1)
                {
                        if (errno == 1)
                                continue;
                        break;
                }
		if (args[0][0] == '.' || args[0][0] == '/' || args[0][0] == '~')
			full_path = args[0];
		else
			full_path = getpath(args[0]);
		execute(full_path, args, av[0]);
	}
	if (cmd != NULL)
		free(cmd);

	return errno;
}

void print_prompt(int is_term)
{
	if (is_term)
		_printf("($) ");
}

void execute(char *full_path, char **args,char * name)
{
	int i;
	pid_t pid;
	extern char **environ;

	if (full_path == NULL)
	{
		_printf("%s: %s: not found\n", name, args[0]);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(full_path, args, environ);
		_printf("%s: %s: no such file or  directory\n",name, args[0]);
		exit(-1);
	}
	else
	{
		wait(&i);
		if (args != NULL)
			free_args(args);
		free(full_path);
	}
}
