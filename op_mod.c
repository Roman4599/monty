#include "monty.h"

/**
 * op_mod - Get the rest of the division of the second top
 *          element by the top element
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE on error
 */
int	op_mod(t_parser *parser)
{
	if (stack_too_short(parser, "can't mod, stack too short"))
		return (EXIT_FAILURE);
	if (!parser->stack->arg)
		return (error(parser->line_number, "division by zero"));
	parser->stack->next->arg %= parser->stack->arg;
	pop_top(parser);
	return (0);
}
