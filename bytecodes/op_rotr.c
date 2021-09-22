#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void op_rotr(stack_t **stack, unsigned int n_line)
{
	stack_t *copy = *stack;
	int i, temp;

	n_line = n_line;
	if (copy == NULL || stack == NULL)
		return;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}

	while (i < (stack_length(stack) - 1) && copy != NULL)
	{
		temp = copy->n;
		copy->n = copy->prev->n;
		copy->prev->n = temp;
		i++;
		copy = copy->prev;
	}
}
