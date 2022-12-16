#include "monty.h"
/**
* get_opcodes - gets the opcode
* @stack: head linked list of a stack
* @lcounter: line_counter
* @file: pointer to a monty file
* @text: content
* Return: no return
*/
int get_opcodes(char *text, stack_t **stack, unsigned int lcounter, FILE *file)
{
	instruction_t opstring[] = {
				{"push", push}, {"pall", pall},
				{"pint", pint}, {"pop", pop},
				{"swap", swap}, {"add", add},
				{"nop", nop}, {"sub", sub},
				{"div", _div},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", pstr},
				{"rotl", rotl},
				{"rotr", rotr},
				{"queue", queue},
				{"stack", _stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *tok;

	tok = strtok(text, " \n\t");
	if (tok && tok[0] == '#')
		return (0);
	glob.arg = strtok(NULL, " \n\t");
	while (opstring[j].opcode && tok)
	{
		if (strcmp(tok, opstring[j].opcode) == 0)
		{	opstring[j].f(stack, lcounter);
			return (0);
		}
		j++;
	}
	if (tok && opstring[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lcounter, tok);
		fclose(file);
		free(text);
		f_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
