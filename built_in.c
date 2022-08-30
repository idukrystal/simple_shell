#include "main.h"

/**
 * ch_dir - changes current working directory
 * @cmd: arguments - directories
 * @name: the name of calling shell
 * Return: some value
 */
int ch_dir(char **cmd, char *name)
{
	int i = 1;
	DIR *dir;

	char *curr = getcwd(NULL, 0), *str = NULL;

	if (cmd[1] == NULL)
	{
		str = getvar("HOME");
	}
	else if (_strcmp(cmd[1], "-")  == 0)
	{
		str = getvar("OLDPWD");
	}
	else
	{
		dir = opendir(cmd[1]);
		if (dir)
		{
			closedir(dir);
			str = cmd[1];
		}
		else
		{
			free(curr);
			print_exec_error("cd", name, errno);
		}
	}
	if (str != NULL)
	{
		chdir(str);
		free(str);
		str = getcwd(NULL, 0);
		_setenv("PWD", str, &i);
		if (_strcmp(str, curr) != 0)
			_setenv("OLDPWD", curr, &i);
		free(str);
		free(curr);
	}
	return (i);
}
