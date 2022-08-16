#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * delete - deletes a node in input index of linked list
 * @head: pointer to input linked list
 * @index: position where new node will be inserted
 *
 * Return: 1 if it succeeded, -1 otherwise
 */
int delete(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *ptr;

	if (!(*head))
		return (-1);
	ptr = malloc(sizeof(stack_t));
	if (!ptr)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next)
			(*head)->next->prev = NULL;
		(*head) = (*head)->next;
		return (1);
	}
	ptr = (*head);
	while (ptr->next && i < index - 1)
	{
		ptr = ptr->next;
		i += 1;
	}
	if (index > i + 1)
		return (-1);
	ptr->next = ptr->next->next;
	ptr->next->prev = ptr->next->prev->prev;
	return (1);
}
