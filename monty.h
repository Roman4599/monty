#ifndef MONTY_H
# define MONTY_H

# include <stdlib.h>

/**
 * struct s_stack - Node of the stack
 * @arg: value held by the node
 * @next: node pushed just before this one
 */
typedef struct s_stack
{
	int		arg;
	struct s_stack	*next;
}	t_stack;

/**
 * struct s_instructions - Node of the list of the instructions
 * @op: name of the instruction
 * @arg: argument of the instruction
 * @next: instruction stored just after this one
 */
typedef struct s_instructions
{
	char			*op;
	int				arg;
	struct s_instructions	*next;
}	t_instructions;

/**
 * struct s_parser - State of the parser
 * @instructions: instructions already read
 * @stack: the stack of the values
 * @line: buffer holding the line being read
 * @len: length of the line being read
 * @cap: capacity of the buffer of the line
 * @line_number: number of the line being read
 * @arg: argument of the instruction being executed
 */
typedef struct s_parser
{
	t_instructions	*instructions;
	t_stack			*stack;
	char			*line;
	int				len;
	int				cap;
	int				line_number;
	int				arg;
}	t_parser;

typedef int	(*t_op_func)(t_parser *parser);

/**
 * struct s_op - Entry of the table of the instructions
 * @name: name of the instruction
 * @func: function executing the instruction
 */
typedef struct s_op
{
	char		*name;
	t_op_func	func;
}	t_op;

int	check_args(int argc, char **argv);
int	open_file(char *path, int *fd);
int	add_instr(t_instructions **instructions, char *op, int arg);
int	parse_file(t_parser *parser, int fd);
int	parse_line(t_parser *parser, char *line);
int	handle_line(t_parser *parser);
int	append_char(t_parser *parser, char c);
t_op	*find_op(char *name);
int	execute_one(char *op, t_parser *parser);
int	op_push(t_parser *parser);
int	op_pall(t_parser *parser);
int	op_pint(t_parser *parser);
int	op_pop(t_parser *parser);
int	op_swap(t_parser *parser);
int	op_add(t_parser *parser);
int	op_sub(t_parser *parser);
int	op_mul(t_parser *parser);
int	op_div(t_parser *parser);
int	op_mod(t_parser *parser);
int	op_nop(t_parser *parser);
int	stack_too_short(t_parser *parser, char *message);
void	pop_top(t_parser *parser);
int	error(int line_number, char *message);
int	unknown_instruction(int line_number, char *op);
int	fatal(char *message);
int	is_number(char *str);
int	is_instruction(char *op);
char	*next_token(char **line);
void	free_stack(t_stack *stack);
void	free_instructions(t_instructions *instructions);
char	*ft_strdup(char *str);
void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *str);
void	ft_putnbr(int fd, int n);
void	ft_putrev(int fd, char *str, int len);

#endif
