#include "monty.h"
/**
 * get_instructions - Returns an array of instruction_t structs
 *
 * Return: An array of instruction_t structs
 */
instruction_t *get_instructions(void)
{
	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	return (instructions);
}
