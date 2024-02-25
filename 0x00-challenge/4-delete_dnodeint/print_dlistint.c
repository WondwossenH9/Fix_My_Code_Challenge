#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints doubly linkedlist of integers
 *
 * @h: pointer to first element of a list
 *
 * Return: number of element printed
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t a;

	a = 0;
	while (h)
	{
		printf("%d\n", h->a);
		h = h->next;
		a++;
	}
	return (a);
}
