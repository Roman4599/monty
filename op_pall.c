#include "monty.h"

/**
 * op_pall - Print the values of the stack from the top to the bottom
 * @parser: the state of the parser
 * Return: 0
 */
int	op_pall(t_parser *parser)
{
	t_stack	*node;

	node = parser->stack;
	while (node)
	{
		ft_putnbr(1, node->arg);
		ft_putchar(1, '\n');
		node = node->next;
	}
	return (0);
}
