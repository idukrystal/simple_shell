#include "main.h"
#include "chris.h"

/**
 * main - a simple shell
 * @ac: argument connt
 * @av: argument array
 * Return: 0 on success or an no that indicates error
 */
int main(int ac, char **av)
{
	char *cmd = NULL, **args = NULL;
	size_t max = 0, runs = 0;
	int w = ac, is_atty = isatty(STDIN_FILENO);
	run_info info = {NULL, 0, 0, 0};

	while (1)
	{
		runs++;
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
		info.exit = 0;
		args = un_alias(args);
		if (run_built_in(args, &info))
			;
		else
			execute(args, &info);
		if (info.err)
			_printf("%s: %i: %s: %s\n", av[0], runs, args[0], info.err_msg);
		if (info.end)
			break;
		free_args(args);
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
 * @info: run info
 */
void execute(char **args, run_info *info)
{
	int i, is_path = 1;
	pid_t pid;
	char *full_path = NULL;
	int status = file_stat(args[0]);

	if (status == 1)
		full_path = args[0];
	else if (status == 0)
	{
		/* full_path = getpath(args[0]); */
		/* is_path = 0; */
		if (full_path == NULL)
			info->err_msg = strclone("not found");
	}
	else if (status == 3)
		info->err_msg = strclone("not found");
	else
		info->err_msg = strclone("Permission denied");
	if (full_path == NULL)
		info->err = 1;
	else
	{
		pid = fork();
		if (pid == 0)
		{
			execve(full_path, args, environ);
			info->err = 1;
			info->err_msg = strclone("cant exec");
			perror("exec");
			info->end = 1;
		}
		else
		{
			wait(&i);
			info->exit = errno;
		}
	}
	if (!is_path)
		free(full_path);
}

/**
 * un_alias - replace  an alias with its value
 * @cmd: alias
 * Return: alias value
 */
char **un_alias(char **cmd)
{
	char **args, **new;
	int i, j, tot;
	alias_t *tmp = get_alias(cmd[0]);

	if (tmp == NULL)
		return (cmd);
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

/**
 * reset - resets run info
 * @info: run info
 */
void reset(run_info *info)
{
	if (info->err_msg != NULL)
		free(info->err_msg);
	info->err_msg = NULL;
	info->end = 0;
	info->err = 0;
}
