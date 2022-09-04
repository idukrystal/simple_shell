#include "main.h"
#include "chris.h"

int main(int ac, char **av)
{
	char *cmd = NULL, **args = NULL;
	size_t max = 0;
	int ret  = 0, w = ac, is_atty = isatty(STDIN_FILENO);
	run_info info = {NULL, 0, 0, 0};

	while (1)
	{
		print_prompt(is_atty);
		w = _getline(&cmd, &max, STDIN_FILENO);
		if (w == -1)
		{
			if (is_atty)
				_putchar('\n');
			break;
		}
		cmd[w - 1] = (cmd[w - 1] == '\n') ? '\0' : cmd[w - 1];
		args = extract_args(cmd, ' ', count_args(cmd, ' '));
		if (args[0] == NULL)
		{
			free_args(args);
			continue;
		}
		args = un_alias(args);
		if (run_built_in(args, &info))
			;
		else
			execute(args, av[0]);
		if (info.err)
			_printf("%s: %s: %s\n", av[0], args[0], info.err_msg);
		printf("end %i\n", info.end);
		if (info.end)
			break;
		reset(&info);
	}
	if (cmd != NULL)
		free(cmd);


	free_alias(*(alias()));
	return (info.exit);
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

	printf("%s %s\n", args[0], full_path);
	if ((args[0][0] == '.') || args[0][0] == '/' || args[0][0] == '~')
		full_path = args[0];
	else
	{
		full_path = getpath(args[0]);
		is_path = 0;
	}
	printf("%s %s\n", args[0], full_path);
	if (full_path == NULL)
	{
		_printf("%s: %s: not found\n", "broo", args[0]);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			execve(full_path, &full_path, NULL);
			print_exec_error(args[0], name, errno);
			exit(0);
		}
		else
		{
			wait(&i);
		}
	}
	if (args != NULL)
		free_args(args);
	if (!is_path)
		free(full_path);
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

char **un_alias(char **cmd)
{
	char **args, **new;
	int i, j , tot;
	alias_t *tmp = get_alias(cmd[0]);

	if (tmp == NULL)
		return cmd;
	args = extract_args(tmp->val, ' ', count_args(tmp->val, ' '));

	tot = count(args) + count(cmd);
	new = malloc(sizeof(*cmd) * tot);

	for (i = 0; args[i] != NULL; i++)
	{
		new[i] = args[i];
	}
	for (j = 1; cmd[j] != NULL; j++, i++)
        {
                new[i] = cmd[j];
        }
	cmd[j] = NULL;
	free(cmd[0]);
	free(cmd);
	free(args);
	return (new);
}

void reset(run_info *info)
{
	if (info->err_msg != NULL)
		free(info->err_msg);
	info->err_msg = NULL;
	info->end = 0;
	info->exit = 0;
	info->err = 0;
}
