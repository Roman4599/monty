# Monty
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

## Usage
```
./monty file
```
where `file` is the path to the file containing Monty byte code

## Monty byte code files
Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Instructions
- `push <int>`: Pushes an element to the stack. Usage: `push <int>` where `<int>` is an integer. If `<int>` is not an integer or if there is no argument given to `push`, prints the error message `L<line_number>: usage: push integer`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `pall`: Prints all the values on the stack, starting from the top of the stack. If the stack is empty, doesn't print anything.

## Examples
```
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
```

## Compilation
```
gcc -Wall -Wextra -Werror -std=c89 *.c -o monty
```
or using the provided Makefile:
```
make
```

## Exit Status
- `EXIT_SUCCESS` on success
- `EXIT_FAILURE` on error

## Authors
[Roman4599](https://github.com/Roman4599)
