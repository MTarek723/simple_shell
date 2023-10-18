#include "shell.h"
/**
 * _atoi - convert a string to an integer.
 *
 * @s: input string
 *
 * Return: converted int from string
*/
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	while (*s != '\0' && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (*s != '\0')
	{
		do {
			num = num * 10 + (*s - '0');
			s++;
		} while (*s >= '0' && *s <= '9');
	}
	return (num * sign);
}
