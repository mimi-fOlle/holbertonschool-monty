#include "monty.h"
#include <stdio.h>

/**
 * add - Adds the top two elements of a stack
 * @stack: The stack to check
 * @line_nb: The Monty file's line number
 */
void add(stack_t **stack, unsigned int line_nb)
{
	stack_t *looper = *stack;
	stack_t *first;
	int stack_nb = 0;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
		is_error = 1;
	}
	else
	{
		while (looper && stack_nb < 2)
		{
			looper = looper->next;
			stack_nb++;
		}

		if (stack_nb != 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_nb);
			is_error = 1;
		}
		else
		{
			looper = *stack;
			first = *stack;

			looper = looper->next;
			looper->n = first->n + looper->n;
			pop(stack, line_nb);
		}
	}
}
