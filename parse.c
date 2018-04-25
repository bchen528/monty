#include "monty.h"

/**
 * parse - parses line of input into tokens
 * @line: line of input to parse
 * @cmd: arguments to send to function
 * Return: 0 means to skip line, 1 means to continue
 */
int parse(char *line, cmd_t *cmd)
{
	char delims[] = " \t\r\n"
	char *op;
	int arg;
	int siz;

	if (cmdline == NULL)
		return (0);

	op = strtok(line, delims);

	if (op == NULL || op[0] == '#')
		return (0);

	if (strcmp(op, "stack") == 0)
	{
		*cmd->mode = 0;
		return (0);
	}

	if (strcmp(op, "queue") == 0)
	{
		*cmd->mode = 1;
		return (0);
	}

	if (strcmp(op, "push") == 0)
	{
		arg = strtok(NULL, delims);
		if (arg == NULL)
		{
			printf("L<line_number>: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
		siz = strlen(arg);
		while (siz--)
			if (arg[siz] > 57 || arg[siz] < 48)
			{
				printf("L<line_number>: usage: push integer\n");
				exit(EXIT_FAILURE);
			}
		cmd->arg = arg;
	}
	cmd->op = op;
	return (1);
}