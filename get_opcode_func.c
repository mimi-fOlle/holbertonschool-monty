#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * get_opcode_func - Executes the function corresponding to a given opcode
 * @opcode: The opcode
 * @stack: The stack on which to execute the function
 * @line_number: The line number of the given opcode
 */
void get_opcode_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			break;
		}
		i++;
	}

	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		is_error = 1;
	}
}
