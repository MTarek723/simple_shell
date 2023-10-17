#include "main.h"
/**
 * excut - main shell excution
 * @argv: the argument vector from main()
 *
 * Return: void
 */
void excut(char **argv)
{
	int stats;
	char *command;
	char *real_command;
	pid_t pid;

	if (sh_strcmp(argv[0], "cd") == 0)
	{
		sh_cd(argv[1]);
		return;
	}
	if (argv)
	{
		command = argv[0];
		real_command = locate(command);
		pid = fork();
		if (pid == 0)
		{
			if (execve(real_command, argv, 0) == -1)
			{
				perror(argv[0]);
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Error:");
		}
		else
		{
			waitpid(pid, &stats, 0);
		}
	}
}
