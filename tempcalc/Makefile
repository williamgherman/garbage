CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

tempcalc: tempcalc.o
	$(CC) -o tempcalc tempcalc.o $(CFLAGS)

tempcalc.o: tempcalc.c
	$(CC) -c tempcalc.c $(CFLAGS)

clean:
	rm -f *.o

install: tempcalc
	sudo cp tempcalc /usr/bin/tempcalc

uninstall: /usr/bin/tempcalc
	sudo rm -f /usr/bin/tempcalc
