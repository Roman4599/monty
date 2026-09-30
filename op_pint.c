#include "monty.h"

/**
 * op_pint - Print the value on the top of the stack
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE if the stack is empty
 */
int	op_pint(t_parser *parser)
{
	if (!parser->stack)
		return (error(parser->line_number, "can't pint, stack empty"));
	ft_putnbr(1, parser->stack->arg);
	ft_putchar(1, '\n');
	return (0);
}
