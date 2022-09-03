#include "chris.h"
#include "main.h"

alias_t *alias = NULL;
/**
 * add_alias - adds alias
 * @name: name fo alias
 * @value: value of alias
 * Return: 1 if successful, -1 otherwise
 */
int add_alias(char *name, char *value)
{
	alias_t *tmp = get_alias(name);
	char *val = strclone(value);
	char *nam;


	if (val == NULL)
		return (-1);
	if (tmp != NULL)
	{
		free(tmp->val);
		tmp->val = val;
		return (1);
	}

	nam = strclone(name);
	if (nam == NULL)
	{
		free(val);
		return (-1);
	}
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
	{
		free(nam);
		free(val);
		return (-1);
	}
	tmp->name = nam;
	tmp->val = val;
	tmp->next = alias;
	alias = tmp;
	return (1);
}

/**
 * get_alias - gets alias and its value
 * @name: name of alias to be found
 * Return: pointer to alias struct or null if non_existent
 */
alias_t *get_alias(char *name)
{
	alias_t *tmp;

	for (tmp = alias; tmp != NULL; tmp = tmp->next)
	{
		if (_strcmp(tmp->name, name) == 0)
		{
			return (tmp);
		}
	}
	return (NULL);
}

/**
 * free_alias - frees alias
 * @list: pointer to head of alias
 * Return: void
 */
void  free_alias(alias_t *list)
{
	alias_t *tmp;
	int i = 0;

	for (tmp = list; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->val != NULL)
			free(tmp->val);

		if (tmp->name != NULL)
			free(tmp->name);
		free(tmp);
	}
}

void print_alias(alias_t *list, int s, char *name)
{
	alias_t *tmp;

	if (s)
	{
		if (list == NULL)
			_printf("%s: %s: not found", name, "alias");
		else
			_printf("alias %s=\'%s\'\n", list->name, list->val);
		return;
	}

	for (tmp = list; tmp != NULL; tmp = tmp->next)
	{
		_printf("alias %s=\'%s\'\n", tmp->name, tmp->val);
	}
}

alias_t  *parse_alias(char *str)
{
	alias_t *tmp = malloc(sizeof(*tmp));
	char *name, *val;
	int i = 0, j, k;

	tmp->next = NULL;
	if (tmp == 0)
		return (NULL);
	while (str[i] != '=' && str[i] != '\0')
		i++;
	name = malloc(sizeof(*name) * (i + 1));

	if (name == NULL)
	{
		free(tmp);
		return (NULL);
	}

	for (j = 0; j <= i; j++)
		name[j] = str[j];
	tmp->name = name;
	if (str[i] == '\0')
	{
		tmp->val = NULL;
		return (tmp);
	}
	tmp->name[i] = '\0';

	while (str[j] != '\0')
		j++;
	val  = malloc(sizeof(*name) * (j - i));
	if (name == NULL)
	{
		free(tmp->name);
		free(tmp);
		return (NULL);
	}
	for (k = ++i; k <= j; k++)
		val[k - i] = str[k];

	unquote(&val);
	tmp->val = val;
	return (tmp);
}
