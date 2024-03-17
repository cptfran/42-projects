# Push_Swap Project

Push_Swap is a project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## Building

To build the project, use the provided Makefile:

```sh
make
```

This will compile the source files and create the executables for the `push_swap` and `checker`.

## Running

After building the project, you can run the `push_swap` executable with a list of integers as arguments:

```sh
./push_swap 4 67 3 87 23
```

The program will output a series of instructions that can sort the list of integers.

To check if the instructions are correct, you can use the `checker` program. It takes the same list of integers as an argument, and reads the instructions from the standard input:

```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

The `checker` program will output `OK` if the instructions sort the list, or `KO` if they don't.

## Cleaning Up

To clean up the build files, you can use the `clean` and `fclean` targets in the Makefile:

```sh
make clean
make fclean
```

`make clean` will remove the object files, and `make fclean` will remove the object files and the executables.

## Rebuilding

To rebuild the project, you can use the `re` target in the Makefile:

```sh
make re
```

This will run `make fclean` followed by `make all`, effectively rebuilding the project from scratch.