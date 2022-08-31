#include "main.h"

int main(int ac, char **av)
{
	char *cmd = NULL, **args = NULL;
	size_t max = 0;
	int ret  = 0, w = ac, is_atty = isatty(STDIN_FILENO);

	while (1)
	{
		print_prompt(is_atty);
		w = _getline(&cmd, &max);
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
		if (args[0] == NULL)
		{
			free_args(args);
			continue;
		}
		ret = (run_built_in(args, av[0]));
		if (ret  != -1)
		{
			if (ret == 1)
				continue;
			break;
		}
		ret = 0;
		execute(args, av[0]);
	}
	if (cmd != NULL)
		free(cmd);

	return (ret);
}

/**
 * print_prompt - print prompt in terminal mode only
 * @is_term: if its in terminal mode
 */
void print_prompt(int is_term)
{
	if (is_term)
		_printf("($) ");
}

/**
 * execute - executes a single program in a new process
 * @args: arguments to pass to the program
 * @name: name of shell that is calling this fumction
 */
void execute(char **args, char *name)
{
	int i, is_path = 1;
	pid_t pid;
	char *full_path = NULL;

	if ((args[0][0] == '.') || args[0][0] == '/' || args[0][0] == '~')
		full_path = args[0];
	else
	{
		full_path = getpath(args[0]);
		is_path = 0;
	}
	if (full_path == NULL)
	{
		_printf("%s: %s: not found\n", name, args[0]);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(full_path, args, environ);
		print_exec_error(args[0], name, errno);
		exit(0);
	}
	else
	{
		wait(&i);
		if (args != NULL)
			free_args(args);
		if (!is_path)
			free(full_path);
	}
}

/**
 * print_exec_error - prints an error message
 * @cmd: the comand that failed
 * @name: the name of the shell that ran that command
 * @err: error no coresponding to error
 */
void print_exec_error(char *cmd, char *name, int  err)
{
	_printf("%s: %s: error - %i\n",name, cmd,  err);
}
