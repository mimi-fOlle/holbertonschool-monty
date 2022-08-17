#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Removes the top element of a stack
 * @stack: The stack to edit
 * @line_nb: The Monty file's line number
 */
void pop(stack_t **stack, unsigned int line_nb)
{
	stack_t *following_deleted = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_nb);
		is_error = 1;
	}
	else
	{
		following_deleted = (*stack)->next;
		if (following_deleted)
			following_deleted->prev = NULL;

		free(*stack);
		*stack = following_deleted;
	}
}
