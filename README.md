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
- `pint`: Prints the value on the top of the stack, followed by a new line. If the stack is empty, prints the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `pop`: Removes the element on the top of the stack. If the stack is empty, prints the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `swap`: Swaps the two elements on the top of the stack. If the stack holds less than two elements, prints the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `add`: Adds the top element of the stack to the second top element of the stack. The result is stored in the second top element and the top element is removed, so the stack is one element shorter and its top holds the result. If the stack holds less than two elements, prints the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `sub`: Subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element and the top element is removed, so the stack is one element shorter and its top holds the result. If the stack holds less than two elements, prints the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `mul`: Multiplies the second top element of the stack with the top element of the stack. The result is stored in the second top element and the top element is removed, so the stack is one element shorter and its top holds the result. If the stack holds less than two elements, prints the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `div`: Divides the second top element of the stack by the top element of the stack. The result is stored in the second top element and the top element is removed, so the stack is one element shorter and its top holds the result. If the stack holds less than two elements, prints the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`. If the top element of the stack is `0`, prints the error message `L<line_number>: division by zero`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `mod`: Computes the rest of the division of the second top element of the stack by the top element of the stack. The result is stored in the second top element and the top element is removed, so the stack is one element shorter and its top holds the result. If the stack holds less than two elements, prints the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exits with status `EXIT_FAILURE`. If the top element of the stack is `0`, prints the error message `L<line_number>: division by zero`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `nop`: Doesn't do anything.
- `pchar`: Prints the char at the top of the stack, followed by a new line. The integer stored at the top of the stack is treated as the ascii value of the character to be printed. If the stack is empty, prints the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exits with status `EXIT_FAILURE`. If the value is not in the ascii table, prints the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exits with status `EXIT_FAILURE`.
- `pstr`: Prints the string starting at the top of the stack, followed by a new line. The integers stored in the stack are treated as the ascii values of the characters to be printed. Printing stops when the stack is empty, when the value is `0`, or when the value is not in the ascii table.
- `rotl`: Rotates the stack to the top. The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.
- `rotr`: Rotates the stack to the bottom. The last element of the stack becomes the top one, and the top element of the stack becomes the second top one.
- `stack`: Sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- `queue`: Sets the format of the data to a queue (FIFO). When the format is a queue, the pushed data is added at the end of the list, otherwise it is added at the top of the list.

## Examples
```
julien@ubuntu:~/monty$ cat -e bytecodes/06.m
push 1$
pint$
push 2$
pint$
push 3$
pint$
julien@ubuntu:~/monty$ ./monty bytecodes/06.m
1
2
3
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

Every error message is written on `stderr`, the values printed by the instructions are written on `stdout`:
- `USAGE: monty file` when the program is called without a file
- `Error: Can't open file HoLbErToN` when the file given as argument can't be opened
- `L<line_number>: usage: push integer` when `push` is used without a valid integer
- `L<line_number>: can't pint, stack empty` when `pint` is used on an empty stack
- `L<line_number>: can't pop an empty stack` when `pop` is used on an empty stack
- `L<line_number>: can't pchar, stack empty` when `pchar` is used on an empty stack
- `L<line_number>: can't pchar, value out of range` when `pchar` is used with a value that is not in the ascii table
- `L<line_number>: can't <opcode>, stack too short` when `swap`, `add`, `sub`, `mul`, `div` or `mod` is used with less than two elements on the stack
- `L<line_number>: division by zero` when `div` or `mod` divides by `0`
- `L<line_number>: unknown instruction <opcode>` when an opcode doesn't exist

## Brainf*ck

The `bf` directory contains Brainf*ck scripts, run with the `bf` interpreter (`sudo apt-get install bf`):

- `1000-school.bf`: Prints `School`, followed by a new line.
- `1001-add.bf`: Reads two digits from stdin, adds them, and prints the result.
- `1002-mul.bf`: Reads two digits from stdin, multiplies them, and prints the result.
- `1003-mul.bf`: Reads two digits from stdin, multiplies them, and prints the result, followed by a new line.

## Authors
[Roman4599](https://github.com/Roman4599)
