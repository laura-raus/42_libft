*This project has been created as part of the 42 curriculum by laraus.*

# libft

`libft` is a custom C library reimplementing foundational standard
library functions alongside additional utility and linked list
operations.

The project serves as the foundational library for future 42 projects
such as:
- get_next_line
- ft_printf
- push_swap

The library is compiled as a static archive:

```txt
libft.a
```

## Overview

The project focuses on:

* low-level memory manipulation
* string handling
* defensive programming
* manual memory management
* linked list operations
* modular C project architecture
* Makefile-based compilation

The repository follows the original 42 project requirements while also
introducing additional repository organization for:

* maintainability
* readability
* testing
* long-term portfolio usage

## Internal Flow

```txt
Application
    ↓
libft.a
    ↓
utility functions
    ↓
memory / strings / lists
```

## Repository Structure

```txt
libft/
├── Makefile
├── README.md
├── .gitignore
├── includes/
│   └── libft.h
├── srcs/
│   ├── libc/
│   ├── additional/
│   └── lists/
├── tests/
│   ├── main_libc.c
│   ├── main_additional.c
│   ├── main_lists.c
│   ├── test_utils.h
│   └── valgrind.sh
└── docs/
    └── en.subject.pdf
```

### Source Organization

The repository separates functions into:

* `libc/` → libc-style reimplementations
* `additional/` → additional utility functions
* `lists/` → linked list operations

This structure improves readability and long-term maintainability while
remaining fully compatible with the original project requirements.

## Compilation

Compile the library:

```bash
make
```

Additional rules:

```bash
make clean
make fclean
make re
```

## Usage

Example:

```c
#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello libft!");
	ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
```

Compilation:

```bash
cc main.c libft.a -Iincludes -o main
./main
```

## Function Categories

### Character Functions

| Function     | Description                 |
| ------------ | --------------------------- |
| `ft_isalpha` | Checks alphabetic character |
| `ft_isdigit` | Checks digit                |
| `ft_isalnum` | Checks alphanumeric         |
| `ft_isascii` | Checks ASCII                |
| `ft_isprint` | Checks printable character  |


### Memory Functions

| Function     | Description              |
| ------------ | ------------------------ |
| `ft_memset`  | Fill memory              |
| `ft_bzero`   | Zero memory              |
| `ft_memcpy`  | Copy memory              |
| `ft_memmove` | Safe memory copy         |
| `ft_memchr`  | Search memory            |
| `ft_memcmp`  | Compare memory           |
| `ft_calloc`  | Allocate and zero memory |


### String Functions

| Function     | Description         |
| ------------ | ------------------- |
| `ft_strlen`  | String length       |
| `ft_strdup`  | Duplicate string    |
| `ft_strchr`  | Find character      |
| `ft_strrchr` | Find last character |
| `ft_strncmp` | Compare strings     |
| `ft_strnstr` | Search substring    |
| `ft_substr`  | Extract substring   |
| `ft_strjoin` | Join strings        |
| `ft_strtrim` | Trim characters     |
| `ft_split`   | Split string        |


### Conversion Functions

| Function  | Description               |
| --------- | ------------------------- |
| `ft_atoi` | Convert string to integer |
| `ft_itoa` | Convert integer to string |


### Output Functions

| Function        | Description             |
| --------------- | ----------------------- |
| `ft_putchar_fd` | Output character        |
| `ft_putstr_fd`  | Output string           |
| `ft_putendl_fd` | Output string + newline |
| `ft_putnbr_fd`  | Output number           |


### Linked List Functions

The linked list implementation uses:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Supported operations include:

* node creation
* insertion
* deletion
* iteration
* mapping
* memory cleanup

| Function          | Description       |
| ----------------- | ----------------- |
| `ft_lstnew`       | Create node       |
| `ft_lstadd_front` | Add node to front |
| `ft_lstadd_back`  | Add node to back  |
| `ft_lstsize`      | Count nodes       |
| `ft_lstlast`      | Get last node     |
| `ft_lstdelone`    | Delete node       |
| `ft_lstclear`     | Clear list        |
| `ft_lstiter`      | Iterate list      |
| `ft_lstmap`       | Map list          |



## Defensive Programming

The implementation includes handling for:

* `NULL` pointers
* allocation failures
* memory safety concerns
* overlapping memory regions
* edge case inputs
* integer overflow-sensitive behavior

Example:

```c
if (!ptr)
	return (NULL);
```

## Testing

The project was tested using:

* custom test programs
* edge case validation
* Valgrind memory checks
* gdb debugging
* comparison against standard libc behavior

The repository includes additional Makefile testing targets
for easier local validation and debugging.

### Build the library

```bash
make
```

### Run tests

#### Libc functions

```bash
make test_libc
```

#### Additional functions

```bash
make test_additional
```

#### Linked list functions

```bash
make test_lists
```

### Run Valgrind checks

#### Libc functions

```bash
make valgrind_libc
```

#### Additional functions

```bash
make valgrind_additional
```

#### Linked list functions

```bash
make valgrind_lists
```

The `tests/` directory contains:

* function validation mains
* edge case testing
* memory leak verification scripts

## Resources

### Documentation

* [Linux man pages](https://man7.org/linux/man-pages/)
* [GNU Make documentation](https://www.gnu.org/software/make/manual/)
* [C language and libc references](https://en.cppreference.com/w/c)

### References

* 42 project subject
* C standard library documentation

## AI Usage

AI tools were used for:

* conceptual clarification
* debugging assistance
* memory management analysis
* edge case review
* documentation refinement

All implementation, integration, testing, and validation were completed manually.

## Notes

Additional testing details and helper documentation are available in
`tests/README.md`.

Developed as part of the 42 curriculum.

This repository is intended for educational, portfolio, and reference purposes.