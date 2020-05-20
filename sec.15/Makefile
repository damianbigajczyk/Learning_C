# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

all: ex15.1 ex15.2

ex15.1: ex15.1.o function.o
	$(CC) ex15.1.o function.o -o ex15.1

ex15.1.o: ex15.1.c
	$(CC) -c ex15.1.c

ex15.2: ex15.2.o function.o
	$(CC) ex15.2.o function.o -o ex15.2

ex15.2.o: ex15.2.c
	$(CC) -c ex15.2.c

function.o: function.c function.h
	$(CC) -c function.c


clean:
	rm -f *.o
	rm -f ex15.1 ex15.2
