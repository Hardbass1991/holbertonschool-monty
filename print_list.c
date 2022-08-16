#include "monty.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_list - prints all the elements of a stack_t list
 * @h: input stack_t
 *
 * Return: number of nodes
 */
size_t print_list(stack_t *h)
{
	int i = 0;
	stack_t *last;

	last = h;
	while (last)
	{
		i += 1;
		printf("%d\n", last->n);
		last = last->next;
	}
	return (i);
}
