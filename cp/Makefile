CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

uninstall: /usr/bin/mycp
	sudo rm -f /usr/bin/mycp

install: cp
	sudo cp cat /usr/bin/mycp

cp: cp.o
	$(CC) -o cp cp.o $(CFLAGS)

cp.o: cp.c
	$(CC) -c cp.c $(CFLAGS)

clean:
	rm *.o
