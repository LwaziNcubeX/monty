#include "monty.h"
/**
 * pall - Prints all the values on the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number of the file where pall was called
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	if (*stack == NULL)
        return;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
