#include "monty.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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
	ssize_t rd = 0;
	size_t n = 0;
	int line_nb = 1;
	FILE *fd;
	int j = 0;
	char *opcode = NULL;
	char *data = NULL;
	char *terminator = NULL;
	char *cur_word;

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

	while (rd = getline(&line, &n, fd) != -1)
	{
		cur_word = strtok(line, " ");

		if (cur_word == NULL)
			continue;

		if (strcmp(cur_word, "push") == 0)
		{
			data = strtok(NULL, " ");
			push(data, &stack, line_nb);
		}
		else
		{
			get_opcode_func(opcode, &stack, line_nb);
		}

		line_nb++;
/*		printf("opcode: %s\n", opcode);
		printf("data: %s\n", data);
*/
	}

	return (EXIT_SUCCESS);
}
