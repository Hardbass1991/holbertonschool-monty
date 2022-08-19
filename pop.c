#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * pop - deletes first node of linked list
 * @head: pointer to input linked list
 *
 * Return: 1 if it succeeded, -1 otherwise
 */
int pop(stack_t **head)
{
	stack_t *temp = *head;

	if (!temp)
		return (-1);
	if (temp->next)
	{
		temp->next->prev = temp->prev;
	}
	*head = temp->next;
	free(temp);
	return (1);
}
