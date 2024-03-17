# Libft

Libft is a project aimed at creating your own C language function library. It includes basic functions that are often used when programming in C.

## Functions

The library includes the following functions:

- Data manipulation: `ft_atoi`, `ft_itoa`, `ft_tolower`, `ft_toupper`
- Memory manipulation: `ft_bzero`, `ft_calloc`, `ft_memchr`, `ft_memcmp`, `ft_memcpy`, `ft_memmove`, `ft_memset`
- String operations: `ft_isalnum`, `ft_isalpha`, `ft_isascii`, `ft_isdigit`, `ft_isprint`, `ft_split`, `ft_strchr`, `ft_strdup`, `ft_striteri`, `ft_strjoin`, `ft_strlcat`, `ft_strlcpy`, `ft_strlen`, `ft_strmapi`, `ft_strncmp`, `ft_strnstr`, `ft_strrchr`, `ft_strtrim`, `ft_substr`
- List operations: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Compilation

The project uses a Makefile, so compilation is simple. Just type `make` in the terminal and the `libft.a` file will be created.

## Usage

To use this library in your project, just include the `libft.h` header file in your source file and add the `-L. -lft` flag during compilation.

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, World!");
    // ...
    return 0;
}

Compilation:
gcc -L. -lft your_file.c
```