#include "shell.h"
/**
 * free_args - free args array.
 *
 * @args: passed array
 * @count: array length
 *
 * Return: Void
*/
void free_args(char **args, int count)
{
	int j;

	for (j = 0; j < count; j++)
	{
		free(args[j]);
	}
}
