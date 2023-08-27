#include "monty.h"
/**
 * mdiv - subtracts the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 **/
void mdiv(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack == 0)
	{
		fprintf(stderr, "L%u: division by zeron", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
