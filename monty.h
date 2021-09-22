#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define VOID_LINE 3
#define REMARK 4
#define USE_CORRECT 2
#define ASCCII_END 0
#define ASCCII_ULIMIT 127
#define BUGLINE -1
#define REMARK_SYM '#'
#define DELIM " "
#define SAME 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int n_line);
} instruction_t;

/**
 * struct global_values - global values needed.
 * @file_bytecode: filepointer to bytecode.
 * @command_array: array with the opcodes.
 *
 * Description: filepointer and opcodes
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_values
{
	FILE *file_bytecode;
	char **command_array;
} all_values;

/*-------GLOBAL VAR-----*/
extern all_values global_var;


/* main.c */
void ch_file(char *file_name);

/* processing_file_name.c */
void buffer_cleaner(char *clean_buff, char *buff_temp, ssize_t n_chars);
int process_input(char *cls_buffer);
void tokenizer(char *cls_buffer);

/* selector.c */
void (*_selector(int, stack_t **))(stack_t **, unsigned int);

/* stak_functions1.c */
void _push(stack_t **stack, unsigned int n_line);
void _pall(stack_t **stack, unsigned int n_line);
void _pint(stack_t **stack, unsigned int n_line);
void _pop(stack_t **stack, unsigned int n_line);
void free_stack(stack_t **stack);

/* stak_functions2.c */
void _swap(stack_t **stack, unsigned int n_line);
void _add(stack_t **stack, unsigned int n_line);
void _nop(stack_t **stack, unsigned int n_line);
void _sub(stack_t **stack, unsigned int n_line);

/* stack_operations.c */
int stack_length(stack_t **stack);

#endif /* MONTY_H */
