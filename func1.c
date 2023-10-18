#include "shell.h"

/**
 * sh_strcat - concatenates two strings
 * @dst: the destination buffer
 * @sorc: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *sh_strcat(char *dst, char *sorc)
{
	char *fin = dst;

	while (*dst)
		dst++;
	while (*sorc)
		*dst++ = *sorc++;
	*dst = *sorc;
	return (fin);
}

/**
 * sh_strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int sh_strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);

	while (*str++)
		len++;
	return (len);
}

/**
 * sh_strcmp - performs lexicogarphic comparison of two strangs.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return:negative if str1 < str2,positive if str1 > str2,zero if str1 == str2
 */
int sh_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}
