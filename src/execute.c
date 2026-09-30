#include "monty.h"
#include <string.h>

/*
** execute - Run every instruction of the list, in order
** instructions: the instruction list (t_instructions **)
** stack: the stack (t_stack **)
** return: 0 on success, EXIT_FAILURE on error (int)
*/
int	execute(t_instructions **instructions, t_stack **stack)
{
	t_instructions	*instr;

	instr = *instructions;
	while (instr)
	{
		if (!strcmp(instr->op, "push"))
		{
			if (op_push(stack, instr->arg))
				return (EXIT_FAILURE);
		}
		else if (!strcmp(instr->op, "pall"))
			op_pall(*stack);
		instr = instr->next;
	}
	return (0);
}
