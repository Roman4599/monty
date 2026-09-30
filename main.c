#include "monty.h"
#include <unistd.h>

/**
 * main - Entry point of the program
 * @argc: number of arguments given to the program
 * @argv: list of the arguments given to the program
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int	main(int argc, char **argv)
{
	t_parser	parser;
	int			fd;
	int			ret;

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	parser.instructions = NULL;
	parser.stack = NULL;
	parser.line = NULL;
	parser.len = 0;
	parser.cap = 0;
	parser.line_number = 1;
	if (open_file(argv[1], &fd))
		return (EXIT_FAILURE);
	ret = parse_file(&parser, fd);
	close(fd);
	free_stack(parser.stack);
	free_instructions(parser.instructions);
	return (ret);
}
