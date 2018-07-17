CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -lncurses

getsize: getsize.o
	$(CC) -o getsize getsize.o $(CFLAGS)

getsize.o: getsize.c
	$(CC) -c getsize.c $(CFLAGS)

clean:
	rm -f *.o

install: getsize
	sudo cp getsize /usr/bin/getsize

uninstall: /usr/bin/getsize
	sudo rm -f /usr/bin/getsize
