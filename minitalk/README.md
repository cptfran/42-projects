# Minitalk Project

Minitalk is a project that allows communication between two processes using UNIX signals.

## Building

To build the project, use the provided Makefile:

```sh
make
```

This will compile the source files and create the executables for the client and server.

## Running

After building the project, you can run the client and server executables using the `run` target in the Makefile:

```sh
make run
```

This will start the server in one terminal and open a new terminal to run the client. The server will display its PID (Process ID). The client will send a message to the server using UNIX signals, and the server will display the received message.

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