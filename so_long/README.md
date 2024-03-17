# So Long Project

So Long is a 2D game project where you control a knight. The goal is to collect all collectibles and reach the exit.

## Building

To build the project, use the provided Makefile:

```sh
make
```

This will compile the source files and create the executable for the game.

## Running
After building the project, you can run the game executable:
```sh
./so_long
```
## Controls
The game is controlled using the W, A, S, and D keys:

W: Move up
A: Move left
S: Move down
D: Move right
You can exit the game at any time by pressing the ESC key.

## Gameplay
Navigate the knight through the game map, collecting all the collectibles. Once all collectibles have been gathered, make your way to the exit to complete the game.

## Cleaning Up
To clean up the build files, you can use the clean and fclean targets in the Makefile:

```sh
make clean
make fclean
```

make clean will remove the object files, and make fclean will remove the object files and the executable.

## Rebuilding
To rebuild the project, you can use the re target in the Makefile:
```sh
make re
```

This will run make fclean followed by make all, effectively rebuilding the project from scratch