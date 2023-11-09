#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: separator to print between numbers
 * @n: number of integers passed to the function
 *
 * Return: no return value (void)
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;

	/* initialize valist for n number of arguments */
	va_start(valist, n);

	/* access all the arguments assigned to valist */
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(valist, int));
		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	printf("\n");

	/* clean memory reserved for valist */
	va_end(valist);
}
