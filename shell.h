#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <libgen.h>
#include <errno.h>

extern char **environ;
#define MAX_INPUT_LENGTH 256

void sh_cd(const char *args, const char *program_name);
void execute_command(const char *input, const char *program_name);
char *sh_getenv(const char *call);
int _strcmp(char *s1, char *s2);
char *sh_strcpy(char *dst, char *sorc);
char *sh_strdup(const char *s);
int sh_putchar(char c);
void sh_puts(char *s);
char *sh_strcat(char *dst, char *sorc);
int sh_strlen(char *str);
int sh_strcmp(const char *str1, const char *str2);
size_t my_strcspn(const char *str, const char *reject);
void print_environment(void);
void free_args(char **args, int count);

#endif
