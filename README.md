# simple_shell

Hello, welcome to our first group project, we're replicating the shell Linux

### version 1.0

## Introduction to the project

Bash is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.

## Evironment
- Language: C
- Editor: VIM 8.1.2269
- Compiler: gcc 9.3.0
- Wall -Werror -Wextra -pedantic -std=gnu89
- Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## Built-in Commands

| Command    | Output          |
|------------|-----------------|
| `env`      | print env       |
| `exit`     | exit shell      |

## Install
To install execute in terminal
`git clone https://github.com/brunonra-dev/simple_shell`

## Compilation

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Valgrind debug

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh`

`valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all -s ./hsh`

# Flowchart

![Flowchart](https://raw.githubusercontent.com/brunonra-dev/simple_shell/main/flowchartnew2.png)

Created by [Bruno Rodríguez](https://github.com/brunonra-dev/) & [Matias López](https://github.com/Matilop15)
