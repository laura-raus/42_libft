# Test Documentation

These tests are small local validation programs for the `libft` project.

They are included for GitHub, learning, debugging, and portfolio purposes.
They are **not part of the official 42 subject requirements** and should not be
treated as mandatory project files for evaluation.

## Purpose

The tests check a minimal but useful set of cases for:

* libc-style functions
* additional string and memory allocation functions
* linked list functions
* edge cases
* memory leaks with Valgrind

The goal is not to replace a full tester, but to keep a small readable
test suite that can quickly confirm whether the library behaves as expected.

## Test Utility Header

The file `test_utils.h` contains shared helper functions used by the
test mains.

### Global Counters

```c
static int	g_total = 0;
static int	g_failed = 0;
````

These counters track:

* total number of checks executed
* number of failed checks

They are declared as `static` inside the header so each test executable
gets its own private counters.

This is acceptable here because the file is only used for local test
programs. Global variables are not used in the actual `libft`
implementation.

## Static Helper Functions

The helper functions are declared as `static` because they are defined
inside a header file.

Example:

```c
static void	check_int(char *label, int got, int expected)
```

Using `static` gives each `.c` file that includes `test_utils.h`
its own private copy of the helper function and avoids linker
conflicts.

This is useful for small test helpers, but it is not a pattern used
in the actual library source code.

## UNUSED Macro

```c
#define UNUSED __attribute__((unused))
```

Some test files include `test_utils.h` but do not use every helper
function.

Because the tests are compiled with:

```bash
-Wall -Wextra -Werror
```

an unused static helper function would normally become a compilation
error.

The `UNUSED` macro tells the compiler that a helper function may be
intentionally unused in some test files.

Example:

```c
static void UNUSED check_size(char *label, size_t got, size_t expected)
```

This macro is only used in the testing helpers, not in the project
source files.

## Output Formatting

The test helpers use formatted `printf` widths to make terminal output
easier to read.

Example:

```c
printf("%-35s | got: %-14d expected: %-14d", label, got, expected);
```

Meaning:

* `%-35s` prints the label left-aligned in a 35-character column
* `%-14d` prints an integer left-aligned in a 14-character column
* `%-12s` prints a string left-aligned in a 12-character column

This creates output such as:

```txt
ft_strlen hello                     | got: 5              expected: 5              OK
ft_strdup                           | got: [hello       ] expected: [hello       ] OK
```

The formatting is only used for readability.

## Running Tests

From the project root:

```bash
make test_libc
make test_additional
make test_lists
```

Each target compiles one test executable and runs it.

## Running Valgrind

From the project root:

```bash
make valgrind_libc
make valgrind_additional
make valgrind_lists
```

Expected successful Valgrind output includes:

```txt
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

Valgrind helps detect:

* memory leaks
* invalid reads
* invalid writes
* double frees
* use-after-free bugs

It does not prove that all logic is correct, so the tests also compare
expected and actual return values.

## Covered Cases

The tests intentionally cover small but important cases:

* empty strings
* normal strings
* `NULL` handling where relevant
* overlapping memory regions
* allocation-based functions
* integer edge cases such as `INT_MIN` and `INT_MAX`
* linked list creation, insertion, iteration, mapping, and clearing

The test suite is intentionally small and readable.
It is designed for local debugging and validation rather than full
automated grading.

## 42 Evaluation Note

The actual `libft` source files should remain compliant with the project
subject and 42 Norm requirements.

The `tests/` folder is extra local tooling.
It is useful for GitHub and personal validation, but it should not be
considered part of the official submitted library.
