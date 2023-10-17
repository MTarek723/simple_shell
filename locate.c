#include "main.h"
/**
 * locate - locate this command in the PATH string
 * @command: the command to find
 *
 * Return: full path of command if found or NULL
 */
char *locate(char *command)
{
char *pth;
char *pth_cpy;
char *pth_tkn;
char *file_pth;
int command_len, dir_len;
struct stat buff;
pth = sh_getenv("PATH");
if (pth)
{
pth_cpy = sh_strdup(pth);
command_len = sh_strlen(command);
pth_tkn = strtok(pth_cpy, ":");
while (pth_tkn != NULL)
{
dir_len = sh_strlen(pth_tkn);
file_pth = malloc(dir_len + command_len + 2);
sh_strcpy(file_pth, pth_tkn);
sh_strcat(file_pth, "/");
sh_strcat(file_pth, command);
sh_strcat(file_pth, "\0");
if (stat(file_pth, &buff) == 0)
{
free(pth_cpy);
return (file_pth);
}
else
{
free(file_pth);
pth_tkn = strtok(NULL, ":");
}
}
free(pth_cpy);
if (stat(command, &buff) == 0)
{
return (command);
}
return (command);
}
return (0);
}
