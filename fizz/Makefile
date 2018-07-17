CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

fizz: fizz.o
	$(CC) -o fizz fizz.o $(CFLAGS)

fizz.o: fizz.c
	$(CC) -c fizz.c $(CFLAGS)

clean:
	rm -f *.o

install: fizz
	sudo cp fizz /usr/bin/fizz

uninstall: /usr/bin/fizz
	sudo rm -f /usr/bin/fizz
