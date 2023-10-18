#include "shell.h"
/**
 * execute_command - main shell excution
 * @input: the argument vector from main()
 * @program_name: a string contain program name.
 * Return: void
 */
void execute_command(const char *input, const char *program_name)
{
	char **args = malloc(sizeof(char *) * MAX_INPUT_LENGTH);
	char *token = strtok((char *)input, " ");
	int i = 0, status;
	pid_t pid;

	while (token != NULL && i < MAX_INPUT_LENGTH - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (i == 0)
		return;
	if (sh_strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (sh_strcmp(args[0], "env") == 0)
	{
		print_environment();
		return;
	}
	if (sh_strcmp(args[0], "cd") == 0)
	{
		sh_cd(args[1], program_name);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		execvp(args[0], args);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	free(args);
}
