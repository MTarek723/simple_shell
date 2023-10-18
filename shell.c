#include "shell.h"
/**
 * main - entry point
 * @argc: arg count
 *
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
*/
int main(int argc, char *argv[])
{
	char input[MAX_INPUT_LENGTH];

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			sh_puts("($) ");
		}
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[my_strcspn(input, "\n")] = '\0';
		if (sh_strcmp(input, "") == 0)
		{
			continue;
		}
		execute_command(input, argv[0]);
	}
	return (0);
}
