CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

rps: rps.o
	$(CC) -o rps rps.o $(CFLAGS)

rps.o: rps.c
	$(CC) -c rps.c $(CFLAGS)

clean:
	rm -f *.o

install: rps
	sudo cp rps /usr/bin/rps

uninstall: /usr/bin/rps
	sudo rm /usr/bin/rps
