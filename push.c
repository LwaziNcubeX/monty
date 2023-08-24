#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number of the file where push was called
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n\r");
	int n;
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = (*stack);
	new_node->prev = NULL;

	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	(*stack) = new_node;
}
