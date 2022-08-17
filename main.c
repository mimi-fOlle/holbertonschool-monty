#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int is_error = 0;

/**
 * main - Interpretes Monty ByteCode files
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 if success, exits with failure status otherwise
 */
int main(int ac, char **av)
{
	char *filename;
	stack_t *stack = NULL;
	stack_t *to_free = stack;
	FILE *stream;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = av[1];
	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	readline(stream, &stack);

	while (stack)
	{
		to_free = stack;
		stack = stack->next;
		free(to_free);
	}
	fclose(stream);

	if (is_error)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
