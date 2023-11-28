#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
 size_t num;

 for (num = 0; h; num++, h = h->next)
 {
 printf("%d\n", h->n);
 /* You can also use putchar(h->n + '0'); */
 }

 putchar('\n');
 return (num);
}
