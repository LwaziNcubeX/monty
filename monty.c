#include "monty.h"

stack_t *stack = NULL;
unsigned int line_number = 0;

int main(int argc, char *argv[])
{
	char *line_buf = NULL, *opcode;
	size_t line_buf_size = 0;
	int i = 0;
	FILE *file;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	check_argc(argc);

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line_buf, &line_buf_size, file) != -1)
	{
		line_number++;
		opcode = strtok(line_buf, " \t\n\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
			free(line_buf);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line_buf);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
