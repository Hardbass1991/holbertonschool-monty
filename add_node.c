#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_node - adds a new node at the beginning of a stack_t list.
 * @head: pointer to the head of the list
 * @n: value to be given to the new node
 *
 * Return: pointer to new element, or NULL if process failed
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = (*head);
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	(*head) = new_node;
	return (*head);
}
