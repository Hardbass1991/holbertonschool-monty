#include "monty.h"
/**
 * free_nodes - function that frees a stack_t list.
 * @head : pointer of struct stack_t
 * Return: nothing
 */
void free_nodes(stack_t *head)
{
	stack_t *temp;

	if (!head)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
