#include "monty.h"

/**
 * _selector - selects function of opcode related to the line of monty.
 * @l: number of line in the monty code.
 * @top: pointer of the top of the stack.
 *
 * Return: pointer to functions related to command.
 */
void (*_selector(int l, stack_t **top))(stack_t **top, unsigned int line_n)
{
	int i = 0;

	instruction_t list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{NULL, NULL}
	};

	for (i = 0; list[i].opcode; i++)
	{
		if (strcmp(global_var.command_array[0], list[i].opcode) == SAME)
		{
			return (list[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
					l, global_var.command_array[0]);
	free_stack(top);
	fclose(global_var.file_bytecode);
	exit(EXIT_FAILURE);
}
