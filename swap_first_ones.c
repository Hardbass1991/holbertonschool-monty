#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * swap_first_ones - swaps first two nodes of linked list
 * @h: pointer to input linked list
 *
 * Return: 1 if successful, -1 otherwise
 */
int swap_first_ones(stack_t **h)
{
	stack_t *tmp = NULL;

	tmp = malloc(sizeof(stack_t));
	if (!tmp)
		return (-1);
	tmp->n = (*h)->next->n;
	tmp->next = (*h);
	tmp->prev = NULL;
	if (*h)
		(*h)->prev = tmp;
	(*h) = tmp;
	delete(h, 2);
	return (1);
}
