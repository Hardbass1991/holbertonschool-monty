#include "monty.h"
/**
 * monty_pint - function prints the value at the top of the stack,
 * followed by a new line.
 * @stack : The pointer to the stck struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
/**
 * monty_pop - function removes the top element of the stack.
 * @stack : The pointer to the stck struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		pop(stack);
}
/**
 * monty_swap - function swaps the top two elements of the stack.
 * @stack : The pointer to the stck struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		swap_first_ones(stack);
	}
}
/**
 * monty_add - function adds the top two elements of the stack.
 * @stack : The pointer to the stck struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		sum_first_ones(stack);
}
/**
 * monty_nop - function doesn't do anything.
 * @stack : The pointer to the stck struct
 * @line_number : The number of the line.
 * Return: nothing
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
