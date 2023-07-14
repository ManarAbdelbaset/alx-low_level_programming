#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: print 0-9 using putchar
 *              while using int variable
 *
 * Return: Always 0 (success)
*/

int main(void)
{
	int digit = 0;

	while (digit <= 9)
	{
	/*convet digit to ASCII represemtation*/
	putchar(digit + '0');
	digit++;
	}
	putchar('\n');

	return (0);
}
