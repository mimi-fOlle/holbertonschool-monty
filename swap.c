#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * swap - Swaps the top two elements of the stack
  * @stack: The stack
  * @line_nb: The Monty line number, unused
  */

void swap(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		is_error = 1;
	}
	else
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;

		if (!tmp->next)
			tmp->next->prev = *stack;
		else
		{
			tmp->next = *stack;
			(*stack)->prev = tmp;
			tmp->prev = NULL;
			*stack = tmp;
		}
	}
}
