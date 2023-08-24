#include "monty.h"
/**
 * swap - Swaps the two top elements of the stack.
 * @stack: A pointer to a pointer to the top node of the stack.
 * @line_number: The line number of the file
 *
 * Return: Always void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
