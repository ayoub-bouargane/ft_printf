*This project has been created as part of the 42 curriculum by aybouarg.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C `printf` function, packaged as a library (`libftprintf.a`). The goal is to learn how variadic functions work in C (`<stdarg.h>`) and how to structure a small, extensible formatting engine.

Supported conversions:

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if `NULL`) |
| `%p` | a pointer in hexadecimal (`0x...`, or `(nil)` if `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned hexadecimal integer (lower / upper case) |
| `%%` | a literal `%` |

The function returns the number of characters printed, like the original `printf`. Only `write` is used for output.

## Instructions

**Compilation**

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`.

**Execution**

```c
#include "ft_printf.h"

int main(void)
{
    int n = ft_printf("Hello %s, you are %d years old (%x)\n", "42", 18, 255);
    ft_printf("printed %d chars\n", n);
    return (0);
}
```

```bash
cc main.c libftprintf.a -o test && ./test
```

## Algorithm and data structure

**Algorithm: single pass over the format string + dispatch.**

1. `ft_printf` calls `va_start` and walks through `format` once, character by character.
2. A normal character is written directly with `ft_putchar`.
3. When a `%` is found (and is followed by a character), the next character is passed to `ft_format`, which dispatches to the matching helper (`ft_putstr`, `ft_putnbr`, `ft_puthex`, ...) and fetches the argument with `va_arg` using the exact type expected (`int` for `%c`/`%d`, `unsigned int` for `%u`/`%x`, `void *` for `%p`, ...).
4. Every helper returns the number of characters it wrote, and `ft_printf` accumulates them in a counter that is returned at the end.

**Number conversion: recursion.** Digits are produced from the least significant one (`n % base`) but must be printed from the most significant one. Recursion solves this without any buffer or allocation: the function first calls itself with `n / base`, then prints `base[n % base]` while unwinding. The same logic is used for decimal (`base 10`) and hexadecimal (`base 16`, with lower or upper case alphabet passed as a parameter). `ft_puthex` takes an `unsigned long` so it can print full 64-bit addresses for `%p`; `INT_MIN` is handled by converting to `long` before negating.

**Data structure:** no custom structure is needed. The only one is `va_list`, which acts as a cursor over the variadic arguments (on x86_64 it tracks the register save area, the current offset and the stack overflow area). It is passed to `ft_format` by reference (it is an array type), so each `va_arg` call advances the same cursor.

**Justification:**
- A plain `if` dispatch is simple, readable, easy to extend with a new specifier and compliant with the Norm.
- Recursion avoids `malloc` (no leaks, no failure case) and keeps each function short.
- Returning a count from every helper keeps the return value correct without global variables.
- Trade-off: one `write` per character is slower than a buffered implementation, but it keeps the code simple and has no flush logic to get wrong.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- The C standard library reference: https://en.cppreference.com/w/c/variadic
- GNU Make manual: https://www.gnu.org/software/make/manual/

**Use of AI:** AI was used as a tutor to explain concepts how `va_list`/`va_arg` work at a low level, registers and the stack,
