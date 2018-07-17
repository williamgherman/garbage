# Garbage

## Description

Garbage is a repository of useless toy programs and basic `coreutils` clones.

## Dependencies

`getsize` requires a `curses` implementation like `ncurses` or similar.
`passgen` requires `sodium`.

## Installation

All programs should include a `Makefile` and some include a primitive install as
follows:

```bash
$ make programname
gcc -c programname.c -Wall -Wextra -Wpedantic -std=c99
gcc -o programname programname.o -Wall -Wextra -Wpedantic -std=c99
$ make install
sudo cp programname /usr/bin/programname
```

NB: Programs that could potentially rewrite system programs are renamed (e.g.,
`myecho` instead of `echo`).
