#include <ctype.h>
#include "monty.h"
/**
 * is_integer - tells whether a string represents an integer
 * @buf: input string
 *
 * Return: 1 if buf represents an integer, 0 otherwise.
 */
int is_integer(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (!isdigit(buf[i]) && buf[i] != '-')
			return (0);
	return (1);
}
