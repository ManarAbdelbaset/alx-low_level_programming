#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - Prints a name by invoking a function through a
 * function pointer.
 * @name: The name to be printed.
 * @f: A function pointer to the function that prints the name.
 *
 * Description: This function takes a name and a function pointer as arguments.
 * It invokes the function pointed to by 'f' and passes
 * the name to it for printing.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
