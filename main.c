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
	char *line = NULL;
	stack_t *stack = NULL;
	stack_t *to_free = stack;
	ssize_t rd = 0;
	size_t n = 0;
	int line_nb = 1;
	FILE *fd;
	char *opcode;
	char *data = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = av[1];
	fd = fopen(filename, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((rd = getline(&line, &n, fd) != -1) && !is_error)
	{
		opcode = strtok(line, "\n ");

		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " ");
			push(data, &stack, line_nb);
		}
		else
		{
			get_opcode_func(opcode, &stack, line_nb);
		}

		line_nb++;
	}

	while (stack)
	{
		to_free = stack;
		stack = stack->next;
		free(to_free);
	}
	free(line);
	fclose(fd);

	if (is_error)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
