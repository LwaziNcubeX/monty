#include "monty.h"
/**
 * mdiv - divides the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 **/
void mdiv(stack_t **stack, unsigned int line_number)
{
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	res = (int) (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}
