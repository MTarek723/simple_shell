#include "shell.h"
/**
 * my_strcspn - This function calculates the length of the initial segment of a
 *	 string that does not contain any characters from a specified set
 *		 of characters.
 * @str:A pointer to a null-terminated string.
 * @reject: A pointer to a null-terminated string that specifies a set of
 *		 characters to search for in the input string.
 * Return:  size_t value, which represents the length of the initial segment
 *		 without any of the characters from the reject string.
*/
size_t my_strcspn(const char *str, const char *reject)
{
	const char *s = str;
	size_t count = 0;
	const char *r;
	int found;

	while (*s)
	{
		r = reject;
		found = 0;
		while (*r)
		{
			if (*s == *r)
			{
				found = 1;
				break;
			}
			r++;
		}
		if (found)
		{
			break;
		}
		s++;
		count++;
	}
	return (count);
}
