#include "monty.h"
#include <stdlib.h>

/**
 * stack_too_short - Check that the stack holds at least two elements
 * @parser: the state of the parser
 * @message: error message used when the stack is too short
 * Return: 0 if the stack holds two elements, EXIT_FAILURE otherwise
 */
int	stack_too_short(t_parser *parser, char *message)
{
	if (parser->stack && parser->stack->next)
		return (0);
	return (error(parser->line_number, message));
}

/**
 * pop_top - Remove the element on the top of the stack
 * @parser: the state of the parser
 * Return: nothing
 */
void	pop_top(t_parser *parser)
{
	t_stack	*node;

	node = parser->stack;
	parser->stack = node->next;
	free(node);
}
