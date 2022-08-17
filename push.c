#include <stdio.h>
#include "monty.h"
#include <stdlib.h>

void push(char *data, stack_t **stack, unsigned int line_number)
{
	stack_t *box;
	
	//printf("============line_number is: %d\n", line_number);
	//printf("data: %s\n", data);
	if (data == NULL)
	{
		printf("L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	box = (stack_t *)malloc(sizeof(stack_t));
	if (box == NULL)
		exit(EXIT_FAILURE);

	box->n = atoi(data);
//	box->next = *stack;
	box->next = NULL;
	box->prev = NULL;

	//printf("box->n: %d & line_number-1 = %d\n", box->n, line_number-1);

	if (*stack == NULL)
	{
		*stack = box;
		//printf("stack= null stack[%d]->n: %d\n", line_number-1, stack[line_number-1]->n);
	}
	else
	{
		(*stack)->prev = box;
		box->next = *stack;
		*stack = box;

		//printf("stack[%d]->n: %d\n", line_number-1, stack[line_number-1]->n);
	}
}
