CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99 -O2 -lsodium

install: passgen
	sudo cp passgen /usr/bin/passgen

uninstall: /usr/bin/passgen
	sudo rm -f /usr/bin/passgen

passgen: passgen.o
	$(CC) -o passgen passgen.o $(CFLAGS)

passgen.o: passgen.c
	$(CC) -c passgen.c $(CFLAGS)

clean:
	rm -f *.o
