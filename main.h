#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
#define EXIT "exit\n"
#define CD "cd\n"
#define ENV "env\n"
#define BUFF_SIZE 1024
#define DELIM " \n"

void sh_cd(const char *args, const char *program_name);
char *locate(char *command);
void excut(char **argv);
char **split(char *buff, int x);
int sh_strcmp(const char *str1, const char *str2);
int sh_strlen(char *str);
char *sh_strcat(char *dst, char *sorc);
void sh_puts(char *s);
int sh_putchar(char c);
char *sh_strdup(const char *s);
char *sh_strcpy(char *dst, char *sorc);
char *sh_getenv(const char *call);
#endif
