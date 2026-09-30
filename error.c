#include "monty.h"

/**
 * error - Print an error message about a line on stderr
 * @line_number: line where the error occurs
 * @message: message to print
 * Return: EXIT_FAILURE
 */
int	error(int line_number, char *message)
{
	ft_putstr(2, "L");
	ft_putnbr(2, line_number);
	ft_putstr(2, ": ");
	ft_putstr(2, message);
	ft_putchar(2, '\n');
	return (EXIT_FAILURE);
}

/**
 * unknown_instruction - Print an unknown instruction error on stderr
 * @line_number: line where the error occurs
 * @op: the unknown opcode
 * Return: EXIT_FAILURE
 */
int	unknown_instruction(int line_number, char *op)
{
	ft_putstr(2, "L");
	ft_putnbr(2, line_number);
	ft_putstr(2, ": unknown instruction ");
	ft_putstr(2, op);
	ft_putchar(2, '\n');
	return (EXIT_FAILURE);
}

/**
 * fatal - Print a global error message on stderr
 * @message: message to print
 * Return: EXIT_FAILURE
 */
int	fatal(char *message)
{
	ft_putstr(2, message);
	ft_putchar(2, '\n');
	return (EXIT_FAILURE);
}
