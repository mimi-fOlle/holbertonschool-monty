#ifndef monty_h
#define monty_h
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int is_error;

void readline(FILE *stream, stack_t **stack);
void get_opcode_func(char *command, stack_t **stack, unsigned int line_nb);
void push(char *data, stack_t **stack, unsigned int line_nb);
void pall(stack_t **stack, unsigned int line_nb);
void pint(stack_t **stack, unsigned int line_nb);
void pop(stack_t **stack, unsigned int line_nb);
void swap(stack_t **stack, unsigned int line_nb);
void add(stack_t **stack, unsigned int line_nb);
void nop(stack_t **stack, unsigned int line_nb);
#endif
