#include "monty.h"

/**
 * op_sub - Subtract the top element from the second top element
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE if the stack is too short
 */
int	op_sub(t_parser *parser)
{
	if (stack_too_short(parser, "can't sub, stack too short"))
		return (EXIT_FAILURE);
	parser->stack->next->arg -= parser->stack->arg;
	pop_top(parser);
	return (0);
}
