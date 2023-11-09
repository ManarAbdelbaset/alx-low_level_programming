#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: separator to print between strings
 * @n: number of strings passed to the function
 *
 * Return: no return value (void)
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;
	char *s;

	/* initialize valist for n number of arguments */
	va_start(valist, n);

	/* access all the arguments assigned to valist */
	for (i = 0; i < n; i++)
	{
		s = va_arg(valist, char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	printf("\n");

	/* clean memory reserved for valist */
	va_end(valist);
}
