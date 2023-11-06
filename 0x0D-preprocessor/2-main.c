#include <stdio.h>

/**
 * main - The main function of the program
 *
 * This program prints the name of the file it was compiled from.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Print the name of the file using the __FILE__ macro */
	printf("%s\n", __FILE__);
	return (0);
}
