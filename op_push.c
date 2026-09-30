#include "monty.h"
#include <stdlib.h>

/**
 * op_push - Push the argument of the instruction on the stack
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE on malloc failure
 */
int	op_push(t_parser *parser)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (fatal("Error: malloc failure"));
	node->arg = parser->arg;
	node->next = parser->stack;
	parser->stack = node;
	return (0);
}
