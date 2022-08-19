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

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	process_file(fp);
	fclose(fp);
	return (0);
}
