#include "monty.h"
/**
 * check_argc - Ensures proper number of arguments
 * @argc: The number of command-line arguments
 */
void check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
