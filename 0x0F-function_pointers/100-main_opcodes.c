#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - Prints the opcodes of a given function.
 * @start: The start address of the function.
 * @num_bytes: The number of bytes to print.
 *
 * Description: This function takes a start address and
 * the number of bytes as input.
 * It prints the opcodes of the function in hexadecimal format.
 */
void print_opcodes(char *start, int num_bytes)
{
	int i;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", start[i] & 0xff);
	}
	printf("\n");
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, 1 if the number of arguments is incorrect,
 * or 2 if the number of bytes is negative.
 */
int main(int argc, char *argv[])
{
	int num_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes((char *)main, num_bytes);

	return (0);
}
