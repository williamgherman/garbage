CC = gcc
CFLAGS =-Wall -Wpedantic -Wextra -std=c99

yes: yes.o
	$(CC) -o yes yes.o $(CFLAGS)

yes.o: yes.c
	$(CC) -c yes.c $(CFLAGS)
