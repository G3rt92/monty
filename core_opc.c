#include "monty.h"
/**
 * push - pushes node to the top of a stack.
 * @head: head pointer of a stack
 * @line_counter: line number.
 * Return: Nothing.
 */
void push(stack_t **head, unsigned int line_counter)
{
	int n;

	int i = 0, flag = 0;

	if (glob.arg)
	{
		if (glob.arg[0] == '-')
			i++;
		for (; glob.arg[i] != '\0'; i++)
		{
			if (glob.arg[i] > 57 || glob.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(glob.file);
			free(glob.text);
			f_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.arg);
	if (glob.lf == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
* pall - prints data of all nodes in a stack.
* @head: head pointer of a stack
* @line_counter: line number.
* Return: nothing.
*/
void pall(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	(void)line_counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * pint - prints value at the top of stack
 * @head: head pointer of stack
 * @line_counter: line_number
 * Return: no return
*/
void pint(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pop - removes the top elem of a stack
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: no return
*/
void pop(stack_t **head, unsigned int line_counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * swap - swap the top two elements of the stack.
 * @head: head pointer of a stack
 * @line_counter: line_number
 * Return: no return
*/
void swap(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_counter);
		fclose(glob.file);
		free(glob.text);
		f_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
