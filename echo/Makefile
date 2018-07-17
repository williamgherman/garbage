CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99

install: echo
	sudo cp echo /usr/bin/myecho

uninstall: /usr/bin/myecho
	sudo rm -f /usr/bin/myecho

echo: echo.o
	$(CC) -o echo echo.o $(CFLAGS)

echo.o: echo.c
	$(CC) -c echo.c $(CFLAGS)

clean:
	rm -f *.o
