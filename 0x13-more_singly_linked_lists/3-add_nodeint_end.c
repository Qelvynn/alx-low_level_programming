#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
 listint_t *new;
 listint_t *last = *head; // renamed temp to last

 // allocate memory for the new node
 new = malloc(sizeof(*new));
 if (!new)
 return (NULL);

 // assign data and next pointer to the new node
 new->n = n;
 new->next = NULL;

 // if the list is empty, make the new node the head
 if (*head == NULL)
 {
 *head = new;
 return (new);
 }

 // traverse the list until the last node
 while (last->next) // added parentheses
 last = last->next;

 // append the new node at the end
 last->next = new;

 // free the memory allocated by malloc
 free(new);

 return (new);
}
