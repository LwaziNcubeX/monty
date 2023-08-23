#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number of the file where pint was called
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
