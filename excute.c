#include "shell.h"
/**
 * execute_command - main shell excution
 * @input: the argument vector from main()
 * @program_name: a string contain program name.
 * Return: void
 */
void execute_command(const char *input, const char *program_name);
void execute_command(const char *input, const char *program_name)
{
	char **args = (char **)malloc(sizeof(char *) * MAX_INPUT_LENGTH);
	char *token = strtok((char *)input, " ");
	char *previous_dir;
	int i = 0, status, exit_status;
	pid_t pid;

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (token != NULL && i < MAX_INPUT_LENGTH - 1)
	{
		args[i] = sh_strdup(token);
		if (args[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (i == 0)
	{
		free(args);
		return;
	}
	if (sh_strcmp(args[0], "exit") == 0)
	{
		if (i > 1)
		{
			exit_status = _atoi(args[1]);
			free_args(args, i);
			free(args);
			exit(exit_status);
		}
		else
		{
			free_args(args, i);
			free(args);
			exit(EXIT_SUCCESS);
		}
	}
	if (sh_strcmp(args[0], "env") == 0)
	{
		print_environment();
		return;
	}
	if (sh_strcmp(args[0], "cd") == 0)
	{
		if (i == 1 || sh_strcmp(args[1], "~") == 0)
			sh_cd(sh_getenv("HOME"), program_name);
		else if (sh_strcmp(args[1], "-") == 0)
		{
			previous_dir = getenv("OLDPWD");
			sh_cd(previous_dir, program_name);
		}
		else
			sh_cd(args[1], program_name);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free_args(args, i);
		free(args);
		_exit(2);
	} else if (pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		free_args(args, i);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (status != 0)
			exit(2);
	}
	free_args(args, i);
	free(args);
}
