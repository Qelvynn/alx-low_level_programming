#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This is the main function that sets a[2] to 98
 * without directly using the array 'a' or modifying the pointer 'p'.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	*(p + 5) = 98; /* Set a[2] to 98 */
	printf("a[2] = %d\n", a[2]); /* Output: a[2] = 98 */
	return (0);
}
