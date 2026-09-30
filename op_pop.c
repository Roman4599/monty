#include "monty.h"

/**
 * op_pop - Remove the element on the top of the stack
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE if the stack is empty
 */
int	op_pop(t_parser *parser)
{
	if (!parser->stack)
		return (error(parser->line_number, "can't pop an empty stack"));
	pop_top(parser);
	return (0);
}
