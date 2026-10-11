#include "monty.h"

/**
 * op_pchar - Print the character at the top of the stack
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE if the stack is empty or
 * the value is out of the ascii range
 */
int	op_pchar(t_parser *parser)
{
	if (!parser->stack)
		return (error(parser->line_number, "can't pchar, stack empty"));
	if (parser->stack->arg < 0 || parser->stack->arg > 127)
		return (error(parser->line_number, "can't pchar, value out of range"));
	ft_putchar(1, (char)parser->stack->arg);
	ft_putchar(1, '\n');
	return (0);
}
