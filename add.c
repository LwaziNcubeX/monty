#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	res = (int) (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}
