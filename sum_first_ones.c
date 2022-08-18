#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * sum_first_ones - sms first two nodes of linked list
 * @h: pointer to input linked list
 *
 * Return: 1 if successful, -1 otherwise
 */
int sum_first_ones(stack_t **h)
{
	(*h)->n += (*h)->next->n;
	delete(h, 1);
	return (1);
}
