#include "shell.h"
/**
 * print_environment - prints the current environment;
 * Return: void
*/
void print_environment(void)
{
	int count = 0, i, j, k;
	char **env = environ;
	char **env_copy;
	char *temp;

	while (*env)
	{
		count++;
		env++;
	}
	env_copy = (char **)malloc(count * sizeof(char *));
	if (env_copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	env = environ;
	for (i = 0; *env; i++, env++)
		env_copy[i] = *env;
	for (i = 0; i < count; i++)
	{
		if (sh_strcmp(env_copy[i], "SHLVL=0") == 0)
		{

			temp = env_copy[i];
			for (j = i; j > 0; j--)
				env_copy[j] = env_copy[j - 1];
			env_copy[j] = temp;
			break;
		}
	}
	for (k = 0; k < count; k++)
	{
		sh_puts(env_copy[k]);
		sh_puts("\n");
	}
	free(env_copy);
}
