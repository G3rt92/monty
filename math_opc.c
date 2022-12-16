#include "monty.h"
/**
 * add - adds the top two elements of stack.
 * @head: head pointer
 * @line_counter: line_count
 * Return: no return
*/
void add(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int aux;

	int len = 0;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
  *sub- sustracts elements of a stack
  *@head: head pointer of a stack
  *@line_counter: line_number
  *Return: Nothing
 */
void sub(stack_t **head, unsigned int line_counter)
{
	stack_t *aux;
	int s, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	s = aux->next->n - aux->n;
	aux->next->n = s;
	*head = aux->next;
	free(aux);
}

/**
 * _div - divides the top two elements of the stack.
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: Nothing
*/
void _div(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int aux;

	int len = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * mul - multiplies the top two elements of the stack.
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: Nothing
*/
void mul(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int aux;
	int len = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: Nothing
*/
void mod(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int aux;
	int len = 0;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
