#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: The null-terminated string to hash.
 *
 * This function creates a hash value from a string by shifting and adding bits
 * Return: The unsigned long int hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381; // Initial hash value
	int c; // Character value

	while ((c = *str++)) // Loop through the string
	{
		hash = (hash << 5) + hash + c; // Update the hash value
	}

	return hash; // Return the hash value
}
