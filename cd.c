#include "shell.h"
/**
 * sh_cd - function to change directory.
 *
 * @args: A string representing the path to which the program should
 *	 change the directory.
 * @program_name: A string containing the name of the program.
 *
 * Return: void.
*/
void sh_cd(const char *args, const char *program_name)
{
	if (args == NULL)
	{
		chdir(sh_getenv("HOME"));
	}
	else
	{
		if (chdir(args) != 0)
		{
			fprintf(stderr, "%s: cd: %s: %s\n", program_name, args, strerror(errno));
		}
	}
}
