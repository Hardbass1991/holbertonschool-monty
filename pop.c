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
	if (!(*head))
		return (-1);
	if ((*head)->next)
		(*head)->next->prev = NULL;
	(*head) = (*head)->next;
	return (1);
}
