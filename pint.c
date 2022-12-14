#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * pint - Prints the value at the top of the stack
  * @stack: The stack
  * @line_nb: The Monty line number, unused
  */

void pint(stack_t **stack, unsigned int line_nb)
{
	stack_t *print_top = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_nb);
		is_error = 1;
	}
	else
		printf("%d\n", print_top->n);
}
