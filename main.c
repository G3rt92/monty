#include "monty.h"
glob_t glob = {NULL, NULL, NULL, 0};
/**
  * main - monty parser
  * @argc: number of arguments.
  * @argv: argument position.
  * Return: EXIT_SUCCESS or EXIT_FAILURE on failure.
  */
int main(int argc, char *argv[])
{
	FILE *file;
	char *text;
	size_t size;
	ssize_t read_line;
	stack_t *stack;
	unsigned int line_counter;

	size = 0;
	read_line = 1;
	line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	glob.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		text = NULL;
		read_line = getline(&text, &size, file);
		glob.text = text;
		line_counter++;
		if (read_line > 0)
		{
			get_opcodes(text, &stack, line_counter, file);
		}
		free(text);
	}
	f_stack(stack);
	fclose(file);
	return (0);
}
