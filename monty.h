#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct cmd_s - file and its content
 * @fd: file descriptor
 * @line: the line of the file
 */
typedef struct cmd_s
{
	FILE *fd;
	char *line;
} cmd_t;

extern cmd_t cmd;
extern int num;

void _usage(int argc);
stack_t *_newnode(int i);
void customPush(stack_t **stack, unsigned int line_number);
void customPall(stack_t **stack, unsigned int line_number);
void customPint(stack_t **stack, unsigned int line_number);
void customPop(stack_t **stack, unsigned int line_number);
void _free_stack(stack_t *stack);
void _clear_stack(stack_t **stack);
void my_interpretor(char *argv);
int _get_opc(stack_t **stack, char *arg, char *val, int line_number);
void _open_error(char *file);
void _push_error(FILE *fd, char *line, stack_t *stack, int line_number);
void _inst_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n);
int _digit(char *c);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _divd(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void is_pstr(stack_t **stack, unsigned int line_number);
void is_rotl(stack_t **stack, unsigned int line_number);
void is_rotr(stack_t **stack, unsigned int line_number);

#endif
