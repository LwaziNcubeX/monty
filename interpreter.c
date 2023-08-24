#include "monty.h"

/**
 * interpret_file - interpret the given file
 *
 * @file: pointer to file to interpret
 */
void interpret_file(FILE *file)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	unsigned int line_number = 0;

	while (getline(&line_buf, &line_buf_size, file) != -1)
	{
		line_number++;
		execute_instruction(line_buf, line_number);
	}

	free(line_buf);
}

/**
 * execute_instruction - execute the given instruction
 *
 * @line_buf: buffer containing the instruction
 * @line_number: line number of the instruction
 */
void execute_instruction(char *line_buf, unsigned int line_number)
{
	char *opcode;
	int i = 0;

	instruction_t *instructions = get_instructions();

	opcode = strtok(line_buf, " \t\n\r");
	if (opcode == NULL || opcode[0] == '#')
		return;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
