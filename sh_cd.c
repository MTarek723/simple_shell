#include "main.h"
/**
 * sh_cd - Changes the current directory of the shellby process.
 * @argv: An array of arguments.
 * @program_name: A pointer to the program name.
 * Return: the directory.
 */
void sh_cd(const char *argv, const char *program_name)
{
if (argv == NULL)
{
chdir(sh_getenv("HOME"));
}
else
{
if (chdir(argv) != 0)
{
perror(argv);
}
}
}
}
