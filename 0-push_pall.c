#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "monty.h"

int get_num_words(char *line)
{
	int i = 0, n = 1;

	while (line[i])
	{
		if (line[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

int main()
{
	FILE *fp;
	char *line = NULL, *token;
	ssize_t read;
	size_t len;
	int i, j = 1;
	char **argv;
	stack_t *stack;
	
	stack = NULL;
	fp = fopen("test.m", "r");
	if (!fp)
	{
		printf("Error: Can't open file test.m");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("%s", line);
		argv = malloc((get_num_words(line) + 2) * sizeof(char *));
		if (!argv)
		{
			printf("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		token = strtok(line, " ");
		i = 0;
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;				
		}
		argv[i - 1][strlen(argv[0]) - 1] = '\0';
		for (i = 0; argv[i] != NULL; i++)
			printf("[%d] %s\n", i, argv[i]);
		if (!strcmp(argv[0], "push"))
		{
			if (!argv[1] || (!atoi(argv[1]) && strcmp(argv[1], "0")))
			{
				printf("L%d: usage: push integer", j);
				exit(EXIT_FAILURE);		
			}
			else
				add_node(&stack, atoi(argv[1]));

		}
		else if (!strcmp(argv[0], "pall"))
			print_list(stack);
		else if (!strcmp(argv[0], "pint"))
		{
			if (!stack)
			{
				printf("L%d: can't pint, stack empty", j);
				exit(EXIT_FAILURE);
			}
			else
				printf("%d\n", stack->n);
		}
		else if (!strcmp(argv[0], "pop"))
		{
			if (!stack)
			{
				printf("L%d: can't pop an empty stack", j);
				exit(EXIT_FAILURE);
			}
			else
				pop(&stack);
		}
		else if (!strcmp(argv[0], "swap"))
		{
			if (!stack->next->n)
			{
				printf("L%d: can't swap, stack too short", j);
				exit(EXIT_FAILURE);
			}
			else
				swap_first_ones(&stack);
		}
		else if (!strcmp(argv[0], "add"))
		{
			if (!stack->next->n)
			{
				printf("L%d: can't add, stack too short", j);
				exit(EXIT_FAILURE);
			}
			else
				sum_first_ones(&stack);
		}
		else if (strcmp(argv[0], "nop"))
		{
			printf("L%d: unknown instruction %s\n", j, argv[0]);
			exit(EXIT_FAILURE);
		}
		free(argv);
	}
	return 0;
}
