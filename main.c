#include "monty.h"
#include <unistd.h>

/*
** main - Entry point of the program
** argc: number of arguments (int)
** argv: arguments of the program (char **)
** return: EXIT_SUCCESS or EXIT_FAILURE (int)
*/
int	main(int argc, char **argv)
{
	t_instructions	*instructions;
	t_stack			*stack;
	int				fd;
	int				ret;

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	instructions = NULL;
	stack = NULL;
	if (open_file(argv[1], &fd))
		return (EXIT_FAILURE);
	ret = parse_file(&instructions, &stack, fd);
	close(fd);
	free_stack(stack);
	free_instructions(instructions);
	return (ret);
}
