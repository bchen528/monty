#include "monty.h"

/**
 * run - run's specified function
 * @cmd: data to pass to function
 */
void run(cmd_t *cmd)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(cmd->op, funcs[i].opcode) == 0)
		{
			funcs[i].f(cmd);
			return;
		}
		i++;
	}

	printf("L%d: unknown instruction <opcode>\n", cmd->line_number);
	exit(EXIT_FAILURE);
}
