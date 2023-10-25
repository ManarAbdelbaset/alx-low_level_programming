#include "main.h"

int is_palindrome_helper(char *s, int start, int end);

/**
 * is_palindrome - Determines whether a given string is a palindrome.
 * @s: The string to be checked.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */

int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);

	return (is_palindrome_helper(s, 0, length - 1));
}

/**
 * is_palindrome_helper - Helper function to recursively check if a string is
 * a palindrome.
 * @s: The string to be checked.
 * @start: The pointer to the starting character.
 * @end: The pointer to the ending character.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */

int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (is_palindrome_helper(s, start + 1, end - 1));
}
