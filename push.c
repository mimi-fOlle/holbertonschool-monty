#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <ctype.h>

void push(char *data, stack_t **stack, unsigned int line_number)
{
	stack_t *box;
	
	//printf("============line_number is: %d\n", line_number);
	//printf("data: %s\n", data);
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
//		box->next = *stack;
		box->next = NULL;
		box->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		is_error = 1;
	}

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
