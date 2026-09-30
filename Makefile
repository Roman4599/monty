NAME	= monty

CFLAGS	= -Wall -Wextra -Werror -O2

SRCS	= src/main.c \
		src/parser.c \
		src/execute.c \
		src/utils.c \
		src/ft_printf.c \
		src/op_push.c \
		src/op_pall.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c includes/monty.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

re: clean all

.PHONY: all clean re
