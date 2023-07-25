#include "main.h"

/**
 * Description: prints a string
 * On success: returns no error
*/

void _puts(char *str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		putchar(*(str + i));
		i++;
	}
	putchar(10);
}
root@fbf02a54c483:/alx-low_level_programming/0x05-pointers_arrays_s
root@fbf02a54c483:/alx-low_level_programming/0x05-pointers_arrays_s
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 *print_rev - Prints a string in reverse order
 *@s: String to reverse
 *Return: Nothing
*/

void print_rev(char *s)
