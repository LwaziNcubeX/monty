#include "monty.h"
/**
 * push - Pushes an element to the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number of the file where push was called
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *num_str = strtok(NULL, " \t\n\r");
	int num;
	stack_t *new_node;

	if (num_str == NULL || (!isdigit(*num_str) && *num_str != '-'))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(num_str);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
