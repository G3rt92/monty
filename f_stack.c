#include "monty.h"
/**
* f_stack - frees a DLL
* @head: head pointer to the stack
*/
void f_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
