NAME	= monty

CFLAGS	= -Wall -Wextra -Werror -O2

SRCS	= main.c \
		check.c \
		read.c \
		parse.c \
		execute.c \
		op_push.c \
		op_pall.c \
		op_pint.c \
		op_pop.c \
		op_swap.c \
		op_add.c \
		op_sub.c \
		op_mul.c \
		op_div.c \
		op_mod.c \
		op_nop.c \
		stack.c \
		error.c \
		ft_printf.c \
		free.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c monty.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

re: clean all

.PHONY: all clean re
