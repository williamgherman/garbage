CC=g++
CFLAGS=-std=c++11

todo: todo.o
	$(CC) -o todo todo.cc $(CFLAGS)
	touch todo.dat

todo.o: todo.cc
	$(CC) -c todo todo.cc $(CFLAGS)
