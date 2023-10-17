#include "main.h"
/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
char *buff;
size_t len = 0;
int x;
int k;
(void) argc;
while (1)
{
if (isatty(STDIN_FILENO))
{
sh_puts("$ "); }
x = getline(&buff, &len, stdin);
if (x == -1)
{
sh_puts("\n");
return (-1); }
if (sh_strcmp(buff, EXIT) == 0)
{
break; }
else if (sh_strcmp(buff, ENV) == 0)
{
for (k = 0; environ[k]; k++)
{
sh_puts(environ[k]);
sh_puts("\n");
}
continue; }
argv = split(buff, x);
if (argv[0] == NULL)
{
continue; }
excut(argv);
fflush(stdout);
for (k = 0; argv[k]; k++)
{
free(argv[k]);
}
}
free(argv);
free(buff);
return (0);
}
