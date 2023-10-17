#include "main.h"
/**
 * **split - splits a string into words. Repeat delimiters are ignored
 * @buff: the input string
 * @x: number of chars
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **split(char *buff, int x)
{
char *buff_cpy;
char **args;
int count = 0, i = 0;
char *tkn;
buff_cpy = malloc(sizeof(char) * x);
sh_strcpy(buff_cpy, buff);
tkn = strtok(buff_cpy, DELIM);
while (tkn != 0)
{
count++;
tkn = strtok(NULL, DELIM);
}
args = malloc(sizeof(char *) * (count + 1));
tkn = strtok(buff, DELIM);
for (i = 0; tkn != 0; i++)
{
args[i] = sh_strdup(tkn);
tkn = strtok(NULL, DELIM);
}
args[i] = 0;
free(buff_cpy);
return (args);
}
