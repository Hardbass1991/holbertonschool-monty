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
	char *line = NULL;
	ssize_t read;
	size_t len = 0, j = 0;
	char **argl;
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
		argl = token_line(line);
		
		if (!strcmp(argl[0], "push"))
		{
			monty_push(&stack, argl[1], j);
		}
		else
		{
			operation_opcode = search_opcode(argl[0]);

			if (operation_opcode.f != NULL)
			{
				operation_opcode.f(&stack, j);
			}
		}
		free(argl);
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
 * token_line - function that split the line.
 * @line : The pointer to bytecode line.
 * Return: The pointer to tokens.
 */
char **token_line(char *line)
{
	char *token = NULL;
	char **arg_tok = NULL;
	int i = 0;

	arg_tok = malloc((get_num_words(line) + 2) * sizeof(char *));
	if (!arg_tok)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	i = 0;
	while (token)
	{
		arg_tok[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	arg_tok[i - 1][strlen(arg_tok[0]) - 1] = '\0';
	return (arg_tok);
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
