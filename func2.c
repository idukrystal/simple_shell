#include <sys/stat.h>
#include "main.h"
#include "chris.h"

/**
 * count - counts
 * @args: string
 * Return: number of count
 */
int count(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	return (i);
}

/**
 * file_stat - checks if a file exists and is executable
 * @path: file path
 * Return: 0 if not an absolute file path 1 if successful 2 if dir 3 if not
 */
int file_stat(const char *path)
{
	struct stat st;
	int len = strlen(path);
	int paths = count_args(path, '/');

	if (paths == 1 && path[0] != '/' && path[len - 1] != '/')
	{
		if (!(is_dir_name(path)))
			return (0);
	}
	if (stat(path, &st) == 0)
	{
		if (S_ISREG(st.st_mode) && st.st_mode & S_IXUSR)
			return (1);
		return (2);
	}
	return (3);
}

/**
 * is_dir_name - checks dfor basic file names
 * @path: filename
 * Return: 1 if know 0 othewise
 */
int is_dir_name(const char *path)
{
	if (_strcmp(path, ".") == 0)
		return (1);
	else if (_strcmp(path, "..") == 0)
		return (1);
	else if (_strcmp(path, "~") == 0)
		return (1);
	return (0);
}

/**
 * get_valid_path - bunch of info and return the path to a program
 * @status: is arg[0] a valid file path
 * @args: arg[0] is a tgr program name or parh
 * @info: you know the vibe
 * @is_path: edits this if arg[0] is a file path
 * Return: a path to a program or NULL
 */
char *get_valid_path(int status, char **args, run_info *info, int *is_path)
{
	char *full_path = NULL;

	if (status == 1)
		full_path = args[0];
	else if (status == 0)
	{
		full_path = getpath(args[0]);
		*is_path = 0;
		if (full_path == NULL)
		{
			info->err_msg = strclone("not found");
			info->exit = 2;
		}
	}
	else if (status == 3)
	{
		info->err_msg = strclone("not found");
		info->exit = 2;
	}
	else
	{
		info->err_msg = strclone("Permission denied");
		info->exit = 13;
	}
	return (full_path);
}
