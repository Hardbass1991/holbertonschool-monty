#include "monty.h"
/**
 * monty_push - function that pushes an element to stack
 * @stack : The pointer to the stck struct
 * @value : 2th argument the line
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_push(stack_t **stack, char *value, unsigned int line_number)
{
	if (!value || (!atoi(value) && strcmp(value, "0")))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		add_node(stack, atoi(value));
	}
}
/**
 * monty_pall - function that prints the file lines
 * @stack : The pointer to the stack struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_list(*stack);
}
