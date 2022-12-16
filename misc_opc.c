#include "monty.h"
/**
  *nop- does nothing
  *@head: head pointer of a stack
  *@line_counter: line_number
  *Return: Nothing
 */
void nop(stack_t **head, unsigned int line_counter)
{
	(void) line_counter;
	(void) head;
}
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: Nothing
*/
void pchar(stack_t **head, unsigned int line_counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: Nothing
*/
void pstr(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
/**
  *rotl- rotates the stack to the top
  *@head: head pointer of a stack
  *@line_counter: line_number
  *Return: Nothing
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int line_counter)
{
	stack_t *aux;
	stack_t *tmp = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
/**
  *rotr- rotates the stack to the bottom
  *@head: head pointer of a stack
  *@line_counter: line_number
  *Return: Nothing
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
	stack_t *h;

	h = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (h->next)
	{
		h = h->next;
	}
	h->next = *head;
	h->prev->next = NULL;
	h->prev = NULL;
	(*head)->prev = h;
	(*head) = h;
}
