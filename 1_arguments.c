#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 *my_interpretor - reads file and executes monty bytecodes
 *@argv: argument vector
 */

void my_interpretor(char *argv)
{
	int line = 0, r = 0;
	size_t size = 0;
	char *token = NULL;
	char *val = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.line, &size, cmd.fd) != -1)
		{
			line++;
			token = strtok(cmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
			{
				continue;
			}
			val = strtok(NULL, " \n\t\r");
			r = _get_opc(&stack, token, val, line);

			if (r == 1)
				_push_error(cmd.fd, cmd.line, stack, line);
			else if (r == -1)
				_inst_error(cmd.fd, cmd.line, stack, token, line);
		}
		free(cmd.line);
		_free_stack(stack);
		fclose(cmd.fd);
	}
	else
	{

		_open_error(argv);

	}
}
