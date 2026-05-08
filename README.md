*This project has been created as part of the 42 curriculum by laraus.*

# Libft

C library of foundational functions including strings, memory, and linked list operations. Completed at 42 School.


# Description

libft is one of the foundational projects at 42.

The goal of the project is to recreate commonly used libc functions while learning:
- memory management
- pointer manipulation
- string handling
- linked lists
- Makefiles
- debugging
- defensive programming

The project also introduces low-level programming concepts such as:
- heap vs stack memory
- undefined behavior
- manual memory allocation
- buffer manipulation
- data structures

The final result is a reusable static C library (`libft.a`) used in future 42 projects such as:
- get_next_line
- push_swap


# Instructions

## Compilation

Compile the library:

```bash
make
```


Remove object files:

```bash
make clean
```

Remove object files and library:

```bash
make fclean
```

Recompile everything:

```bash
make re
```


## Example Usage

Compile with a test file:

```bash
cc main.c libft.a -o main
```

Run:

```bash
./main
```


# Project Structure

```text
libft/
├── Makefile
├── libft.h
├── ft_*.c
├── ft_*.o
```


# Concepts Learned

## Memory Management

Understanding:
- malloc
- calloc
- free
- memory leaks
- heap vs stack
- ownership of allocated memory

Example:

```c
char *s = ft_strdup("hello");
free(s);
```


## Strings in C

C strings are arrays of characters terminated by `'\0'`.

Example:

```c
char str[] = "hello";
```


## Pointers

Using:
- pointers
- double pointers
- void pointers
- function pointers

Example:

```c
void *ptr;
```


## Defensive Programming

Handling:
- NULL protection
- allocation failures
- edge cases
- integer overflow

Example:

```c
if (!ptr)
    return (NULL);
```


## Linked Lists

The project introduces singly linked lists using the structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

Learned operations:
- node creation
- insertion
- deletion
- iteration
- mapping
- memory cleanup


# Library Functions

## Character Functions

| Function | Description |
|---|---|
| ft_isalpha | Checks alphabetic character |
| ft_isdigit | Checks digit |
| ft_isalnum | Checks alphanumeric |
| ft_isascii | Checks ASCII |
| ft_isprint | Checks printable character |


## Memory Functions

| Function | Description |
|---|---|
| ft_memset | Fill memory |
| ft_bzero | Zero memory |
| ft_memcpy | Copy memory |
| ft_memmove | Safe memory copy |
| ft_memchr | Search memory |
| ft_memcmp | Compare memory |
| ft_calloc | Allocate and zero memory |


## String Functions

| Function | Description |
|---|---|
| ft_strlen | String length |
| ft_strdup | Duplicate string |
| ft_strchr | Find character |
| ft_strrchr | Find last character |
| ft_strncmp | Compare strings |
| ft_strnstr | Search substring |
| ft_substr | Extract substring |
| ft_strjoin | Join strings |
| ft_strtrim | Trim characters |
| ft_split | Split string |


## Conversion Functions

| Function | Description |
|---|---|
| ft_atoi | Convert string to integer |
| ft_itoa | Convert integer to string |


## Output Functions

| Function | Description |
|---|---|
| ft_putchar_fd | Output character |
| ft_putstr_fd | Output string |
| ft_putendl_fd | Output string + newline |
| ft_putnbr_fd | Output number |


## Linked List Functions

| Function | Description |
|---|---|
| ft_lstnew | Create node |
| ft_lstadd_front | Add node to front |
| ft_lstadd_back | Add node to back |
| ft_lstsize | Count nodes |
| ft_lstlast | Get last node |
| ft_lstdelone | Delete node |
| ft_lstclear | Clear list |
| ft_lstiter | Iterate list |
| ft_lstmap | Map list |


# 🛠️ Testing & Debugging

The project was tested using:
- custom test files
- edge case testing
- valgrind
- gdb
- comparison with original libc behavior

Example:

```bash
valgrind --leak-check=full ./main
```


# Important Technical Notes

## Undefined Behavior

Example:

```c
char *s = "hello";
s[0] = 'H';
```

Modifying string literals causes undefined behavior.


## Memory Safety

All heap allocations must be properly freed to avoid memory leaks.


## memcpy vs memmove

`memcpy` is unsafe for overlapping memory regions.

`memmove` safely handles overlap.


# Resources

## Documentation

- Linux man pages:
  - https://man7.org/linux/man-pages/
- W3Schools - C Tutorial:
  - https://www.w3schools.com/c/index.php
- GNU Make documentation:
  - https://www.gnu.org/software/make/manual/


## Tutorials & References

- GeeksForGeeks C articles
- 42 intra subject PDF


# AI Usage

AI tools were used as learning assistants during the project.

Usage included:
- conceptual explanations
- debugging guidance
- clarification of memory behavior
- understanding edge cases
- README structure assistance

All code was reviewed, tested, and adapted manually.


⚠️ This project was completed as part of 42 School.  
It is provided for portfolio/review/learning purposes only. Please do not copy for coursework.
