#include <stdio.h>
#include <stdlib.h>

int _isdigit(char *str);
void _multiply(char *num1, char *num2);
void _print_number(char *number);
int _strlen(char *str);

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	_multiply(argv[1], argv[2]);

	return (0);
}

/**
 * _isdigit - Check if a string contains only digits
 * @str: The string to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * _multiply - Multiply two positive numbers
 * @num1: The first number
 * @num2: The second number
 */
void _multiply(char *num1, char *num2)
{
	int len1, len2, i, j, carry, n1, n2, sum;
	int *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = calloc(len1 + len2, sizeof(int));

	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		result[i] += carry;
	}

	_print_number(result);
	free(result);
}

/**
 * _print_number - Print an array of integers as a number
 * @number: The array of integers
 */
void _print_number(char *number)
{
	int i = 0;

	while (number[i] == 0)
		i++;

	if (i == _strlen(number))
		printf("0");
	else
	{
		while (i < _strlen(number))
		{
			printf("%d", number[i]);
			i++;
		}
	}

	printf("\n");
}

/**
 * _strlen - Calculate the length of a string
 * @str: The string
 *
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
