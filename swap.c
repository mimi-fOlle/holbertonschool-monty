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
	stack_t *swop = *stack;
	int stack_nb = 0;
	
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
		is_error = 1;
	}
	else
	{
		while (swop && stack_nb < 2)
		{
			swop = swop->next;
			stack_nb++;
		}

		if (stack_nb != 2)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
			is_error = 1;
		}
		else
		{
			stack_nb = swop->n;
			swop->n = swop->next->n;
			swop->next->n = stack_nb;
		}
	}
}
