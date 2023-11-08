#include "3-calc.h"

/**
 * main - performs simple operations
 * @argc: number of arguments provided to the program
 * @argv: array of strings that contains the arguments
 *
 * Return: 0 if success, otherwise 98, 99 or 100
 */
int main(int argc, char **argv)
{
	int a, b, result;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if (b == 0 && (*argv[2] == '/' || *argv[2] == '%'))
	{
		printf("Error\n");
		return (100);
	}

	op_func = get_op_func(argv[2]);

	if (op_func == NULL)
	{
		printf("Error\n");
		return (99);
	}

	result = op_func(a, b);
	printf("%d\n", result);

	return (0);
}
