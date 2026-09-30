#include "monty.h"
#include <string.h>

static t_op	g_ops[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"pint", op_pint},
	{"pop", op_pop},
	{"swap", op_swap},
	{"add", op_add},
	{"sub", op_sub},
	{"mul", op_mul},
	{"div", op_div},
	{"mod", op_mod},
	{"nop", op_nop},
	{NULL, NULL}
};

/**
 * find_op - Find the entry of an instruction in the table of them
 * @name: name of the instruction to look for
 * Return: the entry of the instruction, NULL if it doesn't exist
 */
t_op	*find_op(char *name)
{
	int	i;

	i = 0;
	while (g_ops[i].name)
	{
		if (!strcmp(g_ops[i].name, name))
			return (&g_ops[i]);
		i++;
	}
	return (NULL);
}

/**
 * execute_one - Execute a single instruction
 * @op: name of the instruction
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE on error
 */
int	execute_one(char *op, t_parser *parser)
{
	t_op	*entry;

	entry = find_op(op);
	if (!entry)
		return (0);
	return (entry->func(parser));
}
