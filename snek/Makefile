CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=gnu11 -lncurses

snek: snek.o
	$(CC) -o snek snek.o $(CFLAGS)

snek.o: snek.c
	$(CC) -c snek.c $(CFLAGS)

clean:
	rm -f *.o

install: snek
	sudo cp snek /usr/bin/snek

uninstall: /usr/bin/snek
	sudo rm -f /usr/bin/snek
