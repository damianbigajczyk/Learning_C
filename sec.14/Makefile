# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

all: ex14.1 ex14.2

ex14.1: ex14.1.o function.o
	$(CC) ex14.1.o function.o -o ex14.1

ex14.1.o: ex14.1.c
	$(CC) -c ex14.1.c

ex14.2: ex14.2.o function.o
	$(CC) ex14.2.o function.o -o ex14.2

ex14.2.o: ex14.2.c
	$(CC) -c ex14.2.c

function.o: function.c function.h
	$(CC) -c function.c

clean:
	rm -f *.o
	rm -f ex14.1
