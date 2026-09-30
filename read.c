#include "monty.h"
#include <unistd.h>

/**
 * append_char - Add one character at the end of the line being read
 * @parser: the state of the parser
 * @c: the character to add
 * Return: 0 on success, EXIT_FAILURE on realloc failure
 */
int	append_char(t_parser *parser, char c)
{
	char	*tmp;

	if (parser->len + 1 >= parser->cap)
	{
		if (parser->cap)
			parser->cap = parser->cap * 2;
		else
			parser->cap = 64;
		tmp = realloc(parser->line, parser->cap);
		if (!tmp)
			return (fatal("Error: realloc failure"));
		parser->line = tmp;
	}
	parser->line[parser->len] = c;
	parser->len++;
	parser->line[parser->len] = '\0';
	return (0);
}

/**
 * handle_line - Execute the line being read then free its memory
 * @parser: the state of the parser
 * Return: 0 on success, EXIT_FAILURE on error
 */
int	handle_line(t_parser *parser)
{
	int	ret;

	ret = 0;
	if (parser->line)
	{
		parser->line[parser->len] = '\0';
		ret = parse_line(parser, parser->line);
	}
	free(parser->line);
	parser->line = NULL;
	parser->len = 0;
	parser->cap = 0;
	return (ret);
}

/**
 * parse_file - Read the file then store and execute every instruction
 * @parser: the state of the parser
 * @fd: file descriptor of the file to read
 * Return: 0 on success, EXIT_FAILURE on error
 */
int	parse_file(t_parser *parser, int fd)
{
	char	c;
	int		ret;

	ret = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			ret = handle_line(parser);
			parser->line_number++;
		}
		else
			ret = append_char(parser, c);
		if (ret)
			return (ret);
	}
	if (parser->len > 0)
		return (handle_line(parser));
	return (0);
}
