#include "monty.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/*
** check_args - Check the arguments given to the program
** argc: number of arguments (int)
** argv: arguments of the program (char **)
** return: 0 if the arguments are valid, EXIT_FAILURE otherwise (int)
*/
int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (fatal("USAGE: monty file"));
	if (!argv[1] || !argv[1][0])
		return (fatal("USAGE: monty file"));
	return (0);
}

/*
** open_file - Open the file given as argument
** path: path of the file (char *)
** fd: file descriptor of the opened file (int *)
** return: 0 if the file is opened, EXIT_FAILURE otherwise (int)
*/
int	open_file(char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (fatal("Error: Can't open file HoLbErToN"));
	return (0);
}

/*
** add_instr - Add an instruction at the end of the instruction list
** instructions: the instruction list (t_instructions **)
** op: the opcode of the instruction (char *)
** arg: the argument of the instruction (int)
** return: 0 on success, EXIT_FAILURE on malloc failure (int)
*/
int	add_instr(t_instructions **instructions, char *op, int arg)
{
	t_instructions	*new;
	t_instructions	*last;

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
	if (!*instructions)
	{
		*instructions = new;
		return (0);
	}
	last = *instructions;
	while (last->next)
		last = last->next;
	last->next = new;
	return (0);
}

/*
** parse_line - Store then execute the instruction(s) of one line
** instructions: the instruction list (t_instructions **)
** line: the line to parse (char *)
** line_number: number of the line in the file (int)
** stack: the stack (t_stack **)
** return: 0 on success, EXIT_FAILURE on error (int)
*/
int	parse_line(t_instructions **instructions, char *line, int line_number, t_stack **stack)
{
	char	*op;
	char	*arg;
	int		value;

	op = next_token(&line);
	if (!op[0])
		return (0);
	arg = next_token(&line);
	if (!strcmp(op, "push"))
	{
		if (!arg[0] || !is_number(arg))
			return (error(line_number, "usage: push integer"));
		value = atoi(arg);
	}
	else if (is_instruction(op))
		value = 0;
	else
		return (unknown_instruction(line_number, op));
	if (add_instr(instructions, op, value))
		return (EXIT_FAILURE);
	return (execute_one(op, value, stack));
}

/*
** append_char - Add one character at the end of a line
** line: the line (char **)
** len: current length of the line (int *)
** cap: current capacity of the line (int *)
** c: the character to add (char)
** return: 0 on success, EXIT_FAILURE on realloc failure (int)
*/
int	append_char(char **line, int *len, int *cap, char c)
{
	char	*tmp;

	if (*len + 1 >= *cap)
	{
		*cap = *cap ? *cap * 2 : 64;
		tmp = realloc(*line, *cap);
		if (!tmp)
			return (fatal("Error: realloc failure"));
		*line = tmp;
	}
	(*line)[*len] = c;
	(*len)++;
	(*line)[*len] = '\0';
	return (0);
}

/*
** handle_line - Parse a complete line then free its memory
** instructions: the instruction list (t_instructions **)
** line: the line (char **)
** len: current length of the line (int *)
** cap: current capacity of the line (int *)
** line_number: number of the line in the file (int)
** stack: the stack (t_stack **)
** return: 0 on success, EXIT_FAILURE on error (int)
*/
int	handle_line(t_instructions **instructions, char **line, int *len, int *cap, int line_number, t_stack **stack)
{
	int	ret;

	ret = 0;
	if (*line)
	{
		(*line)[*len] = '\0';
		ret = parse_line(instructions, *line, line_number, stack);
	}
	else
		ret = parse_line(instructions, "", line_number, stack);
	free(*line);
	*line = NULL;
	*len = 0;
	*cap = 0;
	return (ret);
}

/*
** parse_file - Read the file, then store and execute every instruction
** instructions: the instruction list (t_instructions **)
** stack: the stack (t_stack **)
** fd: file descriptor of the file to read (int)
** return: 0 on success, EXIT_FAILURE on error (int)
*/
int	parse_file(t_instructions **instructions, t_stack **stack, int fd)
{
	char	*line;
	char	c;
	int		cap;
	int		len;
	int		line_number;
	int		ret;

	line = NULL;
	cap = 0;
	len = 0;
	line_number = 1;
	ret = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			ret = handle_line(instructions, &line, &len, &cap, line_number, stack);
			line_number++;
		}
		else
			ret = append_char(&line, &len, &cap, c);
		if (ret)
			return (ret);
	}
	if (len > 0)
		return (handle_line(instructions, &line, &len, &cap, line_number, stack));
	free(line);
	return (0);
}
