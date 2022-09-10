#include "main.h"
#include "chris.h"

/**
 * alias - system wide function to return all alias
 * Return: system alias
 */
alias_t **alias()
{
	static alias_t *alias;

	return (&alias);
}

/**
 * set_mode - todo
 * @ac: todo
 * @file: todo;
 * @fd: todo
 * @is_file: todos
 * @is_atty: todo
 */
void set_mode(int ac, char *file, int *fd, int *is_file, int *is_atty)
{
	if (ac > 1)
	{
		*fd = open(file, O_RDONLY);
		if (*fd == -1)
		{
			perror("");
			exit(errno);
		}
		*is_file = 1;
		*is_atty = 0;
	}
	else
		*fd = STDIN_FILENO;
}

/**
 * save_exit - cmd
 * @cmd: hhh
 * @is_file: yyy
 * @fd: Hahhs
 */
void save_exit(char *cmd, int is_file, int fd)
{
	if (cmd != NULL)
		free(cmd);
	if (is_file)
		close(fd);
}
