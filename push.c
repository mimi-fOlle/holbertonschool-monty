#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <ctype.h>

/**
  * push - Pushes an element to the stack
  * @data: The data
  * @stack: The stack
  * @line_number: The Monty line number, unused
  */

void push(char *data, stack_t **stack, unsigned int line_number)
{
	stack_t *box;
	
	if (data == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		is_error = 1;
	}

	box = (stack_t *)malloc(sizeof(stack_t));
	if (box == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		is_error = 1;
	}
	if (!isdigit(atoi(data)))
	{
		box->n = atoi(data);
		box->next = NULL;
		box->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		is_error = 1;
	}

	if (*stack == NULL)
		*stack = box;
	else
	{
		(*stack)->prev = box;
		box->next = *stack;
		*stack = box;
	}
}
