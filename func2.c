#include "shell.h"
/**
 * sh_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int sh_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *sh_puts - prints an input string
 *@s: the string to be printed
 *
 * Return: Nothing
 */
void sh_puts(char *s)
{
	int k = 0;

	if (!s)
		return;
	while (s[k] != '\0')
	{
		sh_putchar(s[k]);
		k++;
	}
}
