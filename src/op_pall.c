#include "monty.h"

/*
** op_pall - Print every value of the stack, from top to bottom
** stack: the stack (t_stack *)
** return: 0 (int)
*/
int	op_pall(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node)
	{
		ft_putnbr(node->arg);
		ft_putchar('\n');
		node = node->next;
	}
	return (0);
}
