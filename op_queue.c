#include "monty.h"

/**
 * op_queue - Set the format of the data to a queue (FIFO)
 * @parser: the state of the parser
 * Return: 0
 */
int	op_queue(t_parser *parser)
{
	parser->is_queue = 1;
	return (0);
}
