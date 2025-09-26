# Compilation

1. Preprocessor
1. Compilation (produces `.o`/obj files)
        - Will warn if an undefined func exists, like if missing header
        - `.o` files indicate what was declared, but not defined, so it indicates those incomplete
funcs
1. Assembling
1. Linking
        - The linter takes all the `.o` files, links them together so that each has their needed
        dependencies, and produces an executable/binary or lib
        - This will use headers to find package funcs (may need to pair with gcc's `-l` and/or
        `-L`), and may also need to execute with `LB_LIBRARY_PATH` to contain `.so`s.

## Preprocessor

This can be used to define macros.

### `#include <stdio.h>`

Copy the target header into the current file

### `#define`

Define constants or run mode. Note that `-D` can be used to define vars during compilation, like
`-DDEBUG` to `#define DEBUG`.

- `#define DEBUG`
- `#define PI 3.14`

### `#undef`

Undefine a variable.

### `#ifdef`/`#endif`

Check if a variable is defined.

```c
#ifdef DEBUG
// do some stuff
#endif
```

### `#if`/`#elif`/`#else`/`#endif`

Conditional compilation directive.

### `#error`

Generate a compiler error message.

```c
#error "Error message"
```

### `#warning`

Generate a compiler warning message.

```c
#warning "Warning message"
```

### `#pragma`

Does a buncha stuff depending on compiler. `#pragma once` is v common.

## Linking

You can use `ldd` to view the linked libraries.

```sh
$ ldd ./6-allocations
        linux-vdso.so.1 (0x00007f63a3441000)
        libc.so.6 => /lib64/libc.so.6 (0x00007f63a3235000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f63a3443000)
```

