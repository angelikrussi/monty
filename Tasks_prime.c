#include "monty.h"
/**
 * _push - adds a node to thetop of the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _push(stack_t **stack, unsigned int n_line)
{
	stack_t *new_node;
	long int n;
	char *end_point = NULL;

	if (stack == NULL)
	{
		fclose(global_var.file_bytecode);
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fclose(global_var.file_bytecode);
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((global_var.command_array[1]) == NULL)
	{	fclose(global_var.file_bytecode);
		free(new_node);
		free_stack(stack);
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	n = strtol(global_var.command_array[1], &end_point, 10);
	if (end_point == global_var.command_array[1] || *end_point != '\0')
	{	fclose(global_var.file_bytecode);
		free_stack(stack);
		free(new_node);
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	new_node->n = (int)n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - prints all the values in the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _pall(stack_t **stack, unsigned int n_line)
{
	stack_t *copy = *stack;

	n_line = n_line;
	while (copy != NULL)
	{
		fprintf(stdout, "%d\n", copy->n);
		copy = copy->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _pint(stack_t **stack, unsigned int n_line)
{
	if (*stack == NULL)
	{
		fclose(global_var.file_bytecode);
		fprintf(stderr, "L%d: can't pint, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: top of the stack.
 * @n_line: number of line in the monty file.
 *
 * Return: None.
 */
void _pop(stack_t **stack, unsigned int n_line)
{
	stack_t *copy_stack = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fclose(global_var.file_bytecode);
		fprintf(stderr, "L%d: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}

	*stack = copy_stack->next;
	if (copy_stack->next)
	{
		copy_stack->next->prev = copy_stack->prev;
	}
	free(copy_stack);
}

/**
 * free_stack - frees a stack.
 * @stack: pointer to top of a stack.
 *
 * Return: None.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while ((*stack)->next)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	free(*stack);
}
