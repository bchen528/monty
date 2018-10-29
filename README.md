# monty

A custom Monty bytecode interpreter.

## Requirements
  * All files compiled on Ubuntu 14.04 LTS
  * Allow to use max one global variable
  * Usage: `monty file`
    * `file` is the path to the file containing Monty byte code
  * If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
  * If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
    * where <file> is the name of the file
  * If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
    * where is the line number where the instruction appears.
    * Line numbers always start at 1
  * The monty program runs the bytecodes line by line and stop if either:
    * it executed properly every line of the file
    * it finds an error in the file
    * an error occured
  * If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
  * You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
  
## Setup
  ```
  git clone https://github.com/bchen528/monty.git
  gcc -Wall -Werror -Wextra -pedantic *.c -o monty
  ```
  
## Usage Examples
  Implementing the push and pall opcodes:
  ```
  $ cat bytecodes/07.m 
  push 1
  push 2
  push 3
  pall
  pop
  pall
  pop
  pall
  pop
  pall
  $ ./monty bytecodes/07.m 
  3
  2
  1
  2
  1
  1
  ```
  
  Implementing the add opcode:
  ```
  $ cat bytecodes/12.m 
  push 1
  push 2
  push 3
  pall
  add
  pall
  $ ./monty bytecodes/12.m 
  3
  2
  1
  5
  1
  ```
## File Descriptions
  * [monty.c](monty.c) - contains main function
    * `main` - takes filename(s) as an argument
  * [parse.c](parse.c) - contains parse function
    * `parse` - parses commandline input into tokens
  * [eval.c](eval.c) - contains eval function
    * `eval` - evaluate operation given commandline input, stack/queue mode, and line number of file
  * [run.c](run.c) - contains run function
    * `run` - runs specified command function
  * [free_list.c](free_list.c) - contains free_list function
    * `free_list` - frees a stack represented by a doubly linked list
  * [modes.c](modes.c) - contains functions defining stack and queue modes
    * `stack_mode` - change to stack LIFO format
    * `queue_mode` - change to queue FIFO format
  * [stack_calculator.c](stack_calculator.c) - contains custom add, sub, mul, divide, mod functions
    * `add` - adds the top two elements of the stack
    * `sub` - subtracts the top element of the stack from the second top element of the stack
    * `divide` - divides second top element of the stack with the top element of the stack
    * `mul` - multiplies the second top element of the stack with the top element of the stack
    * `mod` - computes the rest of the division of the second top element of the stack by the top element of the stack
  * [stack_mutations.c](stack_mutations.c) - contains custom push, pop, swap, rotate left, rotate right functions
    * `push` - adds a new node at the beginning of a stack_t list, or in queue mode, add node to end
    * `pop` - remove top element of the stack
    * `swap` - swaps the top two elements of the stack
    * `rotl` - rotates the stack to the top
    * `rotr` - rotates the stack to the bottom
  * [stack_printing.c](stack_printing.c) - contains custom print functions for stack elements
    * `pall` - prints all elements of a doubly linked list
    * `pint` - prints the value at the top of the stack, followed by a new line
    * `pchar` - prints the char at the top of the stack, followed by a new line
    * `pstr` - prints the string starting at the top of the stack
    * `nop` - does not do anything
  * [monty.h](monty.h) - header file
  * [brainfuck](brainfuck) - contains answers to brainfuck exercises
    * [1000-holberton.bf](brainfuck/1000-holberton.bf) - prints `Holberton`, followed by a new line
    * [1001-add.bf](brainfuck/1001-add.bf) - add two digits given by the user from stdin and prints result
    * [1002-mul.bf](brainfuck/1002-mul.bf) - multiply two digits given by the user from stdin and prints result
    * [1003-mul.bf](brainfuck/1003-mul.bf) - multiply two digits given by the user from stdin, followed by a newline, prints result.
    
## Authors

* Becky Chen | [GitHub](https://github.com/bchen528)
* Madison Burke | [GitHub](https://github.com/RocketHTML)
