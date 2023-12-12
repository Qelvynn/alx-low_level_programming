#include <stdio.h>

int clear_bit(unsigned long int *n, unsigned int index)
{
    /* Check if index is valid */
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);

    /* Create a mask with a 0 bit at the given index */
    unsigned long int mask = ~(1UL << index);

    /* Bitwise AND n with mask to clear the bit */
    *n = *n & mask;

    /* Return 1 if successful */
    return (1);
}

int main(void)
{
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);
    return (0);
}
