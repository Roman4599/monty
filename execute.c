#include "monty.h"
#include <string.h>

/*
** execute_one - Execute one instruction
** op: the opcode of the instruction (char *)
** arg: the argument of the instruction (int)
** stack: the stack (t_stack **)
** return: 0 on success, EXIT_FAILURE on error (int)
*/
int	execute_one(char *op, int arg, t_stack **stack)
{
	if (!strcmp(op, "push"))
	{
		if (op_push(stack, arg))
			return (EXIT_FAILURE);
	}
	else if (!strcmp(op, "pall"))
		op_pall(*stack);
	return (0);
}
