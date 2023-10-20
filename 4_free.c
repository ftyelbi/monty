#include "monty.h"
/**
 * _free_stack - frees the stack
 * @stack: pointer to the top of stack
 * Return: void
 */
void _free_stack(stack_t *stack)
{
	stack_t *node = NULL;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
/**
 * _clear_stack - frees all nodes in stack
 * @stack: pointer to the top of stack
 * Return: void
 */
void _clear_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	fclose(cmd.fd);
	free(cmd.line);
}
