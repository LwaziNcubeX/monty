#include "monty.h"
/**
 * sub - subtracts the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
