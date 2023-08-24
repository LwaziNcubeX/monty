#include "monty.h"

stack_t *stack = NULL;
/**
 * main - Entry point for the program
 *
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;

	check_argc(argc);

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpret_file(file);

	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
