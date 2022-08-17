#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - Prints all the values on a stack, starting from the top
 * @stack: The stack
 * @line_nb: The Monty line number, unused
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_nb)
{
	stack_t *to_print = *stack;

	while (to_print)
	{
		printf("%d\n", to_print->n);
		to_print = to_print->next;
	}
}

