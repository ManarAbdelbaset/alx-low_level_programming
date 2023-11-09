#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters.
 * @n: number of arguments passed
 * Return: sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list valist;
	unsigned int i, sum = 0;

	/* initialize valist for n number of arguments */
	va_start(valist, n);

	/* access all the arguments assigned to valist */
	for (i = 0; i < n; i++)
		sum += va_arg(valist, int);

	/* clean memory reserved for valist */
	va_end(valist);

	return (sum);
}
