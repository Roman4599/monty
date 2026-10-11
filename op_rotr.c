#include "monty.h"

/**
 * op_rotr - Rotate the stack to the bottom
 * @parser: the state of the parser
 * Return: 0
 */
int	op_rotr(t_parser *parser)
{
	t_stack	*last;
	t_stack	*prev;

	if (!parser->stack || !parser->stack->next)
		return (0);
	prev = parser->stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = parser->stack;
	parser->stack = last;
	return (0);
}
