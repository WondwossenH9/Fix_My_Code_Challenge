#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at an index from a list
 *
 * @head: pointer to the first element of a list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int a;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	a = 0;
	while (a < index && *head != NULL)
	{
		*head = (*head)->next;
		a++;
	}
	if (a != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		free(*head);
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		*head = saved_head;
	}
	return (1);
}
