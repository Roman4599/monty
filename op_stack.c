#include "monty.h"

/**
 * op_stack - Set the format of the data to a stack (LIFO)
 * @parser: the state of the parser
 * Return: 0
 */
int	op_stack(t_parser *parser)
{
	parser->is_queue = 0;
	return (0);
}
