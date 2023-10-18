#include "shell.h"
/**
* sh_getenv - gets the value of an environ variable
* @call: enviromental variable name
*
* Return: the value
*/
char *sh_getenv(const char *call)
{
int i;
for (i = 0; environ[i] != NULL; i++)
{
char *envr = sh_strdup(environ[i]);
char *tkn = strtok(envr, "=");
if (sh_strcmp(tkn, call) == 0)
{
char *val = strtok(NULL, "=");
return (val);
}
free(envr);
}
return (NULL);
}
