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
	char *str_copy;
	int i = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	str_copy = strdup(str);
	if (str_copy == NULL)
		return (NULL);

	words = malloc(sizeof(char *) * (strlen(str_copy) + 1));
	if (words == NULL)
	{
		free(str_copy);
		return (NULL);
	}

	token = strtok(str_copy, " ");
	while (token != NULL)
	{
		words[i] = strdup(token);
		if (words[i] == NULL)
		{
			for (; i >= 0; i--)
				free(words[i]);
			free(words);
			free(str_copy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " ");
	}
	words[i] = NULL;

	free(str_copy);
	return (words);
}
