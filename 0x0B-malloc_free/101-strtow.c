#include <stdlib.h>

/**
 * word_count - helper function to count the number of words in a string
 * @str: the string to analyze
 *
 * Return: the number of words in the string
 */
int word_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
		if ((str[i] != ' ' && str[i + 1] == ' ') ||
				(str[i] != ' ' && str[i + 1] == '\0'))
			count++;

	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, l, word_start, word_end, word_length, count;

	if (str == NULL || *str == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	count = word_count(str);
	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, l = 0; i < count; i++, l++)
	{
		while (str[l] == ' ')
			l++;
		word_start = l;
		while (str[l] != ' ' && str[l] != '\0')
			l++;
		word_end = l;
		word_length = word_end - word_start;
		words[i] = malloc((word_length + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}
		for (k = 0; k < word_length; k++)
			words[i][k] = str[word_start + k];
		words[i][k] = '\0';
	}
	words[i] = NULL;
	return (words);
}
