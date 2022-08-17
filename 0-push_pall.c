#include "monty.h"
/**
 * main - function main.
 * @ac : The number of arguments
 * @av : The pointer to an array of inputed arguments.
 * Return: always (0);
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL, *token;
	ssize_t read;
	size_t len;
	int i, j = 1;
	char **argv;
	stack_t *stack;
	instruction_t operation_opcode;

	if (ac != 2)
		fprintf(stderr, "%s\n", "USAGE: monty file");

	stack = NULL;
	fp = fopen(av[1], "r");
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
			monty_push(&stack, argv[1], j);
		}
		else
		{
			operation_opcode = search_opcode(argv[0]);

			if (operation_opcode.f != NULL)
			{
				operation_opcode.f(&stack, j);
			}
		}
		free(argv);
	}
	return (0);
}
/**
 * search_opcode - function that pushes an element to stack
 * @opcode : look the opcode to run
 * Return: a instruction_t structure
 */
instruction_t search_opcode(char *opcode)
{
	int i = 0;

	instruction_t option[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{NULL, NULL}
	};

	for (i = 0; option[i].f != NULL; i++)
	{
		if (strcmp(option[i].opcode, opcode) == 0)
		{
			return (option[i]);
		}
	}

	return (option[i]);
}
/**
 * get_num_words - function get number of words in a line.
 * @line : string.
 * Return: number of words.
 */
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
