#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: of the file where the pop instruction was found
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
