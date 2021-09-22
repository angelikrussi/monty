#include "monty.h"

/**
 * _swap - prints all the values in the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _swap(stack_t **stack, unsigned int n_line)
{
	int temp;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.file_bytecode);
		free_stack(stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * _add - adds the top two elements of the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _add(stack_t **stack, unsigned int n_line)
{
	int sum = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.file_bytecode);
		free_stack(stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	_pop(stack, n_line);
}

/**
 * _nop - Does nothing.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _nop(stack_t **stack, unsigned int n_line)
{
	stack = stack;
	n_line = n_line;
}

/**
 * _sub - subtracts the top two elements of the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _sub(stack_t **stack, unsigned int n_line)
{
	int sub = 0;

	if (stack_length(stack) < 2)
	{
		fclose(global_var.file_bytecode);
		free_stack(stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;
	_pop(stack, n_line);
}
