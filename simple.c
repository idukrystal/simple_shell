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
	int w = ac, is_atty = isatty(STDIN_FILENO), is_file = 0, fd;
	run_info info = {NULL, 0, 0, 0};

	set_mode(ac, av[1], &fd, &is_file, &is_atty, av[0]);
	while (1)
	{
		runs++;
		print_prompt(is_atty);
		w = _getline(&cmd, &max, fd);
		kabir(w, is_atty);
		if (w == -1)
			break;
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
			execute(args, &info);
		if (info.err)
			fprintf(stderr, "%s: %lu: %s: %s\n", av[0], runs, args[0], info.err_msg);
		if (info.end)
		{
			reset(&info);
			break;
		}
		free_args(args);
		reset(&info);
	}
	save_exit(cmd, is_file, fd);
	free_alias(*(alias()), 0);
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
	int i, is_path = 1, status = file_stat(args[0]);
	pid_t pid;
	char *full_path = get_valid_path(status, args, info, &is_path);

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
			if (WIFEXITED(i))
			{
				info->exit = WEXITSTATUS(i);
			}
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
	int i = 0, j, tot;
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
