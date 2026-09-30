#include "monty.h"
#include <fcntl.h>

/**
 * check_args - Check the arguments given to the program
 * @argc: number of arguments given to the program
 * @argv: list of the arguments given to the program
 * Return: 0 if the arguments are valid, EXIT_FAILURE otherwise
 */
int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (fatal("USAGE: monty file"));
	if (!argv[1] || !argv[1][0])
		return (fatal("USAGE: monty file"));
	return (0);
}

/**
 * open_file - Open the file given as argument
 * @path: path of the file to open
 * @fd: receives the file descriptor of the opened file
 * Return: 0 if the file is opened, EXIT_FAILURE otherwise
 */
int	open_file(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (fatal("Error: Can't open file HoLbErToN"));
	return (0);
}

/**
 * last_instr - Get the last node of the list of the instructions
 * @instructions: first node of the list of the instructions
 * Return: the last node of the list, NULL if the list is empty
 */
static t_instructions	*last_instr(t_instructions *instructions)
{
	while (instructions->next)
		instructions = instructions->next;
	return (instructions);
}

/**
 * add_instr - Add an instruction at the end of the list
 * @instructions: the list of the instructions
 * @op: name of the instruction to add
 * @arg: argument of the instruction to add
 * Return: 0 on success, EXIT_FAILURE on malloc failure
 */
int	add_instr(t_instructions **instructions, char *op, int arg)
{
	t_instructions	*new;

	new = malloc(sizeof(t_instructions));
	if (!new)
		return (fatal("Error: malloc failure"));
	new->op = ft_strdup(op);
	if (!new->op)
	{
		free(new);
		return (fatal("Error: malloc failure"));
	}
	new->arg = arg;
	new->next = NULL;
	if (*instructions)
		last_instr(*instructions)->next = new;
	else
		*instructions = new;
	return (0);
}
