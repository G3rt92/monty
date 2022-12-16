#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
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
 * struct glob_s - variables -args, file, line text
 * @arg: arg pointer
 * @file: pointer to monty script file
 * @text: line content
 * @lf: flag change stack <-> queue
 * Description: makes available values through the app
 */
typedef struct glob_s
{
	char *arg;
	FILE *file;
	char *text;
	int lf;
}  glob_t;
extern glob_t glob;
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void parser(FILE *file);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
int get_opcodes(char *text, stack_t **head, unsigned int lcounter, FILE *file);
void f_stack(stack_t *head);
void pop(stack_t **head, unsigned int line_counter);
void swap(stack_t **head, unsigned int line_counter);
void add(stack_t **head, unsigned int line_counter);
void nop(stack_t **head, unsigned int line_counter);
void sub(stack_t **head, unsigned int line_counter);
void _div(stack_t **head, unsigned int line_counter);
void mul(stack_t **head, unsigned int line_counter);
void mod(stack_t **head, unsigned int line_counter);
void pchar(stack_t **head, unsigned int line_counter);
void pstr(stack_t **head, unsigned int line_counter);
void rotl(stack_t **head, unsigned int line_counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void queue(stack_t **head, unsigned int line_counter);
void _stack(stack_t **head, unsigned int line_counter);
#endif
