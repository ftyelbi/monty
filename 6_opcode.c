#include "monty.h"

/**
 * _get_opc - gets the opcode function
 * @stack: pointer to the top of stack
 * @arg: the argument
 * @val: the value
 * @line_number: the line number
 * Return: 0 on success || 1 if not a digit || -1 on error
 */

int _get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"customPush", customPush},
		{"customPall", customPall},
		{"customPint",customPint},
		{"is_pstr", is_pstr},
		{"is_rotl", is_rotl},
		{"is_rotr", is_rotr},
		{"customPop", customPop},
		{"_add", _add},
		{"_swap", _swap},
		{"_nop", _nop},
		{"_sub", _sub},
		{"_mul", _mul},
		{"_div", _divd},
		{"_mod", _mod},
		{"_pchar", _pchar},
		{NULL, NULL}
	};
	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_digit(val) == 1)
					num = atoi(val);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (-1);

	return (0);
}
