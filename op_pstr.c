#include "monty.h"

/**
 * op_pstr - Print the string stored in the stack from the top
 * @parser: the state of the parser
 * Return: 0
 */
int	op_pstr(t_parser *parser)
{
	t_stack	*node;
	int		c;

	node = parser->stack;
	while (node)
	{
		c = node->arg;
		if (c == 0 || c < 0 || c > 127)
			break;
		ft_putchar(1, (char)c);
		node = node->next;
	}
	ft_putchar(1, '\n');
	return (0);
}
