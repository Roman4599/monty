#include "monty.h"
#include <stdlib.h>

/*
** op_push - Push a value on the stack
** stack: the stack (t_stack **)
** arg: the value to push (int)
** return: 0 on success, EXIT_FAILURE on malloc failure (int)
*/
int	op_push(t_stack **stack, int arg)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (fatal("malloc failure"));
	node->arg = arg;
	node->next = *stack;
	*stack = node;
	return (0);
}
