#include "monty.h"

all_values global_var = {NULL, NULL};

/**
 * main - main function of the monty processing.
 * @argc: integer with the amount of arguments.
 * @argv: array with pointers to each argument.
 *
 * Return: EXIT_SUCCESS if success, EXIT_FAILURE instead.
 */
int main(int argc, char *argv[])
{
	ssize_t eof = 0;
	char cls_buffer[5000], *buffer[2000];
	stack_t *stack = NULL;
	unsigned int n_line = 0;
	void (*stak_function)(stack_t **, unsigned int);

	global_var.command_array = buffer;
	if (argc == USE_CORRECT)
	{
		ch_file(argv[1]);
		global_var.file_bytecode = fopen(argv[1], "r");
		if (global_var.file_bytecode == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		while (eof != EOF)
		{
			n_line++;
			eof = process_input(cls_buffer);
			if (eof == EOF)
			{
				fclose(global_var.file_bytecode);
				free_stack(&stack);
				return (EXIT_SUCCESS);
			}
			if (eof == VOID_LINE || eof == REMARK)
			{
				continue;
			}
			stak_function = _selector(n_line, &stack);
			stak_function(&stack, n_line);
		}
	}
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * ch_file - checks if the files have the corresponding permissions
 * if not, it exits.
 * @file_name: name of the monty file.
 *
 * Return: None.
 */
void ch_file(char *file_name)
{
	int access_permission;

	access_permission = access(file_name, F_OK);
	if (access_permission == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	access_permission = access(file_name, R_OK);
	if (access_permission == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
}
