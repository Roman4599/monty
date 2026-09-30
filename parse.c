#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_number - Check that a string only contains a valid integer
 * @str: the string to check
 * Return: 1 if the string is an integer, 0 otherwise
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

/**
 * is_instruction - Check that an opcode exists in this version
 * @op: the opcode to check
 * Return: 1 if the opcode exists, 0 otherwise
 */
int	is_instruction(char *op)
{
	if (!strcmp(op, "push") || !strcmp(op, "pall"))
		return (1);
	return (0);
}

/**
 * next_token - Extract the next word of a line, spaces ignored
 * @line: pointer on the line, moved to the end of the word
 * Return: the extracted word, empty when the line is over
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

/**
 * parse_line - Store then execute the instruction of one line
 * @parser: the state of the parser
 * @line: the line to parse
 * Return: 0 on success, EXIT_FAILURE on error
 */
int	parse_line(t_parser *parser, char *line)
{
	char	*op;
	char	*arg;
	int		value;

	op = next_token(&line);
	if (!op[0])
		return (0);
	arg = next_token(&line);
	if (!strcmp(op, "push") && (!arg[0] || !is_number(arg)))
		return (error(parser->line_number, "usage: push integer"));
	if (strcmp(op, "push") && !is_instruction(op))
		return (unknown_instruction(parser->line_number, op));
	value = 0;
	if (!strcmp(op, "push"))
		value = atoi(arg);
	if (add_instr(&parser->instructions, op, value))
		return (EXIT_FAILURE);
	return (execute_one(op, value, &parser->stack));
}
