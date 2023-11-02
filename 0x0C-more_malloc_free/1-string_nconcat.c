#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of bytes from s2 to concatenate.
 *
 * Return: A pointer to the concatenated string (s1 + s2).
 *         NULL if memory allocation fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *concat;

	/* Check if s1 is NULL, treat it as an empty string */
	if (s1 == NULL)
		s1 = "";

	/* Check if s2 is NULL, treat it as an empty string */
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of s1 and s2 */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* Adjust n if it's greater or equal to s2's length */
	if (n >= len2)
		n = len2;

	/* Allocate memory for the concatenated string */
	concat = malloc((len1 + n + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 to the concatenated string */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Concatenate the first n bytes of s2 */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* Add null terminator */
	concat[i] = '\0';

	return (concat);
}
