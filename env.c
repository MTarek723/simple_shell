#include "shell.h"
/**
 * print_environment - prints the current environment;
 * Return: void
*/
void print_environment(void)
{
	char **env = environ;

	while (*env)
	{
		sh_puts(*env);
		sh_puts("\n");
		env++;
	}
}
