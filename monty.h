#ifndef MONTY_H
# define MONTY_H

# include <stdlib.h>

typedef struct s_stack
{
	int				arg;
	struct s_stack	*next;
}	t_stack;

typedef struct s_instructions
{
	char				*op;
	int					arg;
	struct s_instructions	*next;
}	t_instructions;

int		check_args(int argc, char **argv);
int		open_file(char *path, int *fd);
int		parse_file(t_instructions **instructions, t_stack **stack, int fd);
int		parse_line(t_instructions **instructions, char *line, int line_number, t_stack **stack);
int		handle_line(t_instructions **instructions, char **line, int *len, int *cap, int line_number, t_stack **stack);
int		append_char(char **line, int *len, int *cap, char c);
int		add_instr(t_instructions **instructions, char *op, int arg);
int		execute_one(char *op, int arg, t_stack **stack);
int		op_push(t_stack **stack, int arg);
int		op_pall(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_instructions(t_instructions *instructions);
int		error(int line_number, char *message);
int		unknown_instruction(int line_number, char *op);
void	error_prefix(int line_number);
int		fatal(char *message);
int		is_number(char *str);
int		is_instruction(char *op);
char	*next_token(char **line);
char	*ft_strdup(char *str);
void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *str);
void	ft_putnbr(int fd, int n);

#endif
