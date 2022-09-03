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
