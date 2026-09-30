#include "monty.h"

/**
 * op_swap - Swap the two elements on the top of the stack
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE if the stack is too short
 */
int	op_swap(t_parser *parser)
{
	t_stack	*first;
	t_stack	*second;

	first = parser->stack;
	if (!first || !first->next)
		return (error(parser->line_number, "can't swap, stack too short"));
	second = first->next;
	first->next = second->next;
	second->next = first;
	parser->stack = second;
	return (0);
}
