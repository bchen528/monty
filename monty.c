#include "monty.h"

/**
 * main - entry point
 * @argc: number of args
 * @argv: filenames
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *line;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fd)) != -1)
	{
		printf("%s", line);
	}

	return (EXIT_SUCCESS);
}
