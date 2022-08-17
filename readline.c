#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * readline - Extracts opcode from a stream and executes it
 * @stream: Stream to read
 */
void readline(FILE *stream, stack_t **stack)
{
	ssize_t rd = 0;
	size_t n = 0;
	char *opcode;
	char *data;
	char *line = NULL;
	int line_nb = 0;

	while ((rd = getline(&line, &n, stream) != -1) && !is_error)
	{
		line_nb++;
		opcode = strtok(line, "\n ");

		if (opcode == NULL)
		{
			continue;
		}

		if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, "\n ");
			push(data, stack, line_nb);
		}
		else
		{
			get_opcode_func(opcode, stack, line_nb);
		}
	}

	free(line);
}
