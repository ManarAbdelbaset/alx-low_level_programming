#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	char *token;
	int i = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = malloc(sizeof(char *) * (strlen(str) + 1));
	if (words == NULL)
		return (NULL);

	token = strtok(str, " ");
	while (token != NULL)
	{
		words[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		strcpy(words[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	words[i] = NULL;

	return (words);
}
