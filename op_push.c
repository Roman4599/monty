#include "monty.h"
#include <stdlib.h>

/**
 * op_push - Push a value on the stack
 * @stack: the stack
 * @arg: the value to push
 * Return: 0 on success, EXIT_FAILURE on malloc failure
 */
int	op_push(t_stack **stack, int arg)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (fatal("Error: malloc failure"));
	node->arg = arg;
	node->next = *stack;
	*stack = node;
	return (0);
}
