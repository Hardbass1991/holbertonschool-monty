#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	FILE *fp;
	char *line = NULL;
	ssize_t read;
	size_t len;
	fp = fopen("test.m", "r");
	if (!fp)
		exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Length: %ld\n", read);
		printf("%s", line);
	}
	return 0;
}
