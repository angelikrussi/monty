#include "monty.h"

/**
 * process_input - processes each line of the file introduced.
 * @cls_buffer: buffer without initial spaces.
 *
 * Return: EOF if end of file is reached, EXIT_FAILURE if getline fails.
 */
int process_input(char *cls_buffer)
{
	char *buffer_tmp = NULL;
	size_t length = 0;
	ssize_t n_characters = 0;

	*cls_buffer = '\0';
	n_characters = getline(&buffer_tmp, &length, global_var.file_bytecode);
	if (n_characters == BUGLINE)
	{
		free(buffer_tmp);
		return (EOF);
	}
	buffer_cleaner(cls_buffer, buffer_tmp, n_characters);
	if (*cls_buffer == '\0')
	{
		free(buffer_tmp);
		return (VOID_LINE);
	}
	if (*cls_buffer == REMARK_SYM)
	{
		free(buffer_tmp);
		return (REMARK);
	}
	free(buffer_tmp);
	tokenizer(cls_buffer);

	return (EXIT_SUCCESS);
}

/**
 * tokenizer - tokenizes a line to an array.
 * @cls_buffer: buffer without initial spaces.
 *
 * Return: None.
 */
void tokenizer(char *cls_buffer)
{
	int i = 0;
	char *token = NULL;

	while (1)
	{
		token = strtok(((i == 0) ? cls_buffer : NULL), DELIM);
		global_var.command_array[i] = token;
		if (token == NULL)
			break;
		i++;
	}
}

/**
 * buffer_cleaner - removes initial spaces from line and \\n line jump.
 * @cls_buffer: buffer without initial spaces.
 * @buffer_temp: buffer with initial spaces.
 * @n_chars: number of characters in getline.
 *
 * Return: None.
 */
void buffer_cleaner(char *cls_buffer, char *buffer_temp, ssize_t n_chars)
{
	int i = 0, j = 0, start_letters = 0;

	while (i < n_chars)
	{
		if (buffer_temp[i] != ' ')
		{
			start_letters = 1;
		}
		if (start_letters == 1)
		{
			cls_buffer[j] = buffer_temp[i];
			j++;
		}
		i++;
	}
	cls_buffer[j - 1] = '\0';
}
