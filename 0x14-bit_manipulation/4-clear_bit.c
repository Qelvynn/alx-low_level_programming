#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - This prog sets value of a bit to 0 at a given index
 * @num: parameter
 * @bit_index: index
 * Return: 1 if success, -1 if error
 */
int clear_bit(unsigned long int *num, unsigned int bit_index)
{
 // check if the index is valid
 if (bit_index > sizeof(*num) * 8) // added parentheses
 return (-1);

 // use bitwise AND with the complement of a shifted 1 to clear the bit
 *num &= ~(1 << bit_index);

 return (1);
}

