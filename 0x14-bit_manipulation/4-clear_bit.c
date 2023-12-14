#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to an unsigned long int
 * @index: index of the bit to clear
 * Return: 1 if successful, -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	/* check if index is valid */
	if (index > 63)
		return (-1);

	/* create a mask with a 1 at the index */
	mask = 1UL << index;

	/* clear the bit at the index if it is set */
	if (*n & mask)
		*n = *n & ~mask;

	return (1);
}
