#include "monty.h"
/**
 * is_number - checks if the given string is a number
 *
 * @s: string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	if (s == NULL)
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && i == 0)
			continue;

		if (isdigit(s[i]) == 0)
			return (0);
	}

	return (1);
}
