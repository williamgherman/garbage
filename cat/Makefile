CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

uninstall: /usr/bin/mycat
	sudo rm -f /usr/bin/mycat

install: cat
	sudo cp cat /usr/bin/mycat

cat: cat.o
	$(CC) -o cat cat.o $(CFLAGS)

cat.o: cat.c
	$(CC) -c cat.c $(CFLAGS)

clean:
	rm *.o
