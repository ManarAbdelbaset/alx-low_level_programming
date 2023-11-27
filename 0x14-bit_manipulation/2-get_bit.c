#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to get the bit from
 * @index: index at which to get the bit
 *
 * Return: value of the bit, or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(n) * 8))
		return (-1);
	return ((n >> index) & 1);
}