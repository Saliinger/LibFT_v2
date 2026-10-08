*This project has been created as part of the 42 curriculum by alnoukan.*

## Description

**Libft** is the very first project at 42, designed to help you build a personalized C library from scratch. The library contains a collection of general-purpose functions that mimic standard C library (`libc`) functions, along with additional custom utility functions and linked list manipulation tools. This library serves as a foundational toolkit that can be reused across future C projects in the curriculum.

The project is structured into three main parts:

1. **Part 1 - Libc Functions**: Re-implementations of standard C library functions (such as memory manipulation, string handling, character classification, and conversions).
2. **Part 2 - Additional Functions**: Custom utility functions not found in standard libc (such as substring creation, string joining, splitting, integer-to-string conversion, and file descriptor output functions).
3. **Part 3 - Linked List Functions**: Utility functions designed to create, manage, and traverse dynamic singly linked lists.

---

## Instructions

### Compilation

To compile the library and generate the static archive (`libft.a`), use the provided Makefile at the root of your repository:

```bash
make

```

### Makefile Rules

* **`make`**: Compiles source files and generates `libft.a`.
* **`make clean`**: Removes all object (`.o`) files.
* **`make fclean`**: Removes object files as well as the generated `libft.a` archive.
* **`make re`**: Performs a full re-compilation (`fclean` followed by `make`).
* **`make bonus`**: Compiles both mandatory functions and bonus linked list routines.

### Usage

To use the library in your C projects, include the header file:

```c
#include "libft.h"

```

And link the archive during compilation:

```bash
cc main.c libft.a

```

---

## Detailed Library Overview

### Part 1: Libc Re-implementations

* **Character Checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
* **String Manipulation & Search**: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
* **Memory Management**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
* **Conversions & Allocations**: `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_calloc`, `ft_strdup`

### Part 2: Additional Functions

* **String Utilities**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
* **Number Conversion**: `ft_itoa`
* **File Descriptor Output**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3: Linked List Functions

* **Node Operations**: `ft_lstnew`, `ft_lstdelone`, `ft_lstclear`
* **List Management**: `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstiter`, `ft_lstmap`

---

## Resources & AI Usage

### Resources

* **Official Manual Pages (`man`)**: Primary reference for defining function prototypes, expected behaviors, and edge cases for standard libc functions.
* **GitHub & Testing Suites**: Reference repositories and public unit testers (such as `libft-unit-test`) used during local debugging and peer evaluation practice.

### AI Usage

* **AI Tools**: Artificial intelligence was utilized exclusively for drafting and structuring this `README.md` file layout and organizing project documentation requirements. No AI tools were used to generate, write, or solve the C source code or logic for the library functions, keeping strictly in line with 42’s learning objectives and individual peer-evaluation preparedness.