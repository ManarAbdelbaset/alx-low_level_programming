#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: no return value (void)
 */

void print_all(const char * const format, ...)
{
	va_list valist;
	unsigned int i = 0, j;
	char *s, *sep = "";

	/* create list of formats */
	va_start(valist, format);

	while (format && format[i])
	{
		j = 1;
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(valist, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(valist, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(valist, double));
				break;
			case 's':
				s = va_arg(valist, char *);
				if (s == NULL)
					s = "(nil)";
				printf("%s%s", sep, s);
				break;
			default:
				j = 0;
				break;
		}
		sep = ", ";
		i += j;
	}

	printf("\n");
	va_end(valist);
}
