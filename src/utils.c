#include "monty.h"
#include <string.h>

/*
** error - Print an error message related to a line of the file
** line_number: line where the error occurs (int)
** message: message to print (char *)
** return: EXIT_FAILURE (int)
*/
int	error(int line_number, char *message)
{
	ft_putstr("L");
	ft_putnbr(line_number);
	ft_putstr(": ");
	ft_putstr(message);
	ft_putchar('\n');
	return (EXIT_FAILURE);
}

/*
** fatal - Print a global error message, not related to a line
** message: message to print (char *)
** return: EXIT_FAILURE (int)
*/
int	fatal(char *message)
{
	ft_putstr(message);
	ft_putchar('\n');
	return (EXIT_FAILURE);
}

/*
** is_number - Check if a string only contains a valid integer
** str: the string to check (char *)
** return: 1 if the string is an integer, 0 otherwise (int)
*/
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** is_instruction - Check if an opcode exists in this version
** op: the opcode to check (char *)
** return: 1 if the opcode exists, 0 otherwise (int)
*/
int	is_instruction(char *op)
{
	if (!strcmp(op, "push") || !strcmp(op, "pall"))
		return (1);
	return (0);
}

/*
** next_token - Extract the next word of a line, spaces ignored
** line: pointer on the line, moved to the end of the word (char **)
** return: the extracted word, empty if the line is over (char *)
*/
char	*next_token(char **line)
{
	char	*start;
	char	*cursor;

	cursor = *line;
	while (*cursor == ' ' || *cursor == '\t' || *cursor == '\r')
		cursor++;
	start = cursor;
	while (*cursor && *cursor != ' ' && *cursor != '\t' && *cursor != '\r')
		cursor++;
	if (*cursor)
	{
		*cursor = '\0';
		cursor++;
	}
	*line = cursor;
	return (start);
}

/*
** ft_strdup - Duplicate a string in a new allocated memory
** str: the string to duplicate (char *)
** return: the duplicated string (char *)
*/
char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(strlen(str) + 1);
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
** free_stack - Free every node of the stack
** stack: the stack to free (t_stack *)
** return: nothing
*/
void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/*
** free_instructions - Free every node of the instruction list
** instructions: the list to free (t_instructions *)
** return: nothing
*/
void	free_instructions(t_instructions *instructions)
{
	t_instructions	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->op);
		free(instructions);
		instructions = next;
	}
}
