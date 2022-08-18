#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

/**
 * push - Pushes an element to the stack
 * @data: The data
 * @stack: The stack
 * @line_number: The Monty line number, unused
 */

void push(char *data, stack_t **stack, unsigned int line_number)
{
	stack_t *box;
	int i = 0;

	if (data == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		is_error = 1;
		return;
	}

	box = malloc(sizeof(stack_t));
	if (!box)
	{
		fprintf(stderr, "Error: malloc failed\n");
		is_error = 1;
		return;
	}
	while (data[i])
	{
		if (data[0] == '-')
			i++;
		if (data[i] < 48 || data[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ++line_number);
			is_error = 1;
			return;
		}
		i++;
	}
	box->n = atoi(data);
	box->next = NULL;
	box->prev = NULL;
	if (!*stack)
		*stack = box;
	else
	{
		(*stack)->prev = box;
		box->next = *stack;
		*stack = box;
	}
}
