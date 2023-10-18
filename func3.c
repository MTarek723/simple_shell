#include "shell.h"
/**
 * sh_strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *sh_strdup(const char *s)
{
	int len = 0;
	char *fin;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	fin = malloc(sizeof(char) * (len + 1));
	if (!fin)
		return (NULL);
	for (len++; len--;)
		fin[len] = *--s;
	return (fin);
}

/**
 * sh_strcpy - copies a string
 * @dst: the destination
 * @sorc: the source
 *
 * Return: pointer to destination
 */
char *sh_strcpy(char *dst, char *sorc)
{
	int i = 0;

	if (dst == sorc || sorc == 0)
		return (dst);
	while (sorc[i] != '\0')
	{
		dst[i] = sorc[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
