# Monty 

- Monty is a language that aims to close the gap between scripting and programming languages. This is a scripting language that is first compiled into a Monty bytecode like Python. It is based on a single stack with specific instructions for manipulating it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements
-   All files compiled on Ubuntu 14.04 LTS
-   Allow to use max one global variable
-   Usage:  `monty file`
    -   where  `file`  is the path to the file containing Monty byte code
-   If the user does not give any file or more than one argument to your program, print the error message  `USAGE: monty file`, followed by a new line, and exit with the status  `EXIT_FAILURE` .




## Available operation codes:


| Operation code | Description |
|--|--|
|push | Push an item onto the stack. for example (pushing 1 # pushes 1 onto the stack) | 
 | pall | Prints all the values ​​in the stack, starting from the to of the stack. |
  | pint | Prints the value at the top of the stack. | 
  | pop | Removes item a from the stack. | | exchange | Changes the top to stack items. |
   | add |Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.|
| nop | This opcode does not do anything.|
| sub | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed. 



##   Compilation and output

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty monty_file.m
```

-   Any prints from ` stdout ` 
-   Any error message prints ` stderr ` 


## Examples:

- A file named 00.m containing the push and pall opcode implementation:

```
  $ cat bytecodes/00.m
  push 1
  push 2
  push 3
  pall
  $ ./monty bytecodes/00.m
  3
  2
  1
  ```
- Implementing the Pint opcode:

```
  $ cat bytecodes/06.m
  push 1
  pint
  push 2
  pint
  push 3
  pint
  $ ./monty bytecodes/06.m
  1
  2
  3

```
- Implementing the pop opcode: 
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
- Implementing the swap opcode: 
 ```

$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m 
3
2
1
2
3
1
```
- Implementing the sub opcode:

```
$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
$ ./monty bytecodes/19.m 
7
2
1
``` 
## Authors 
Juan Sebastián Tovar.
Mogollon Stefania Russi.   
