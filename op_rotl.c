#include "monty.h"

/**
 * op_rotl - Rotate the stack to the top
 * @parser: the state of the parser
 * Return: 0
 */
int	op_rotl(t_parser *parser)
{
	t_stack	*head;
	t_stack	*tail;

	if (!parser->stack || !parser->stack->next)
		return (0);
	head = parser->stack;
	parser->stack = head->next;
	tail = parser->stack;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}
