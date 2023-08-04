#include "main.h"

/**
 * _strchr - Returns a pointer to the first occurrence
 * of the character c in the string s, or Null if the
 * character is not found
 *
 * @s: string targeted
 * @c: character targeted
 *
 * Return: returns pointer to first occurence of c
*/

char *_strchr(char *s, char c)
{
	int itr;

	for (itr = 0; s[itr] >= '\0' ; itr++)
	{
		if (s[itr] == c)
		{
			return (s + itr);
		}
	}
	return ('\0');
}
