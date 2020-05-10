# -*- MakeFile -*-

#select the compiler and flags
CC = gcc
CFLAGS = -Wall -g

all: ex11.1 ex11.2 ex11.3 ex11.4 ex11.5 ex11.6 ex11.7 ex11.8 ex11.9 ex11.10\
	ex11.11 ex11.12 ex11.13 ex11.14 ex11.15 ex11.16

ex11.11: ex11.11.o function.o
	$(CC) ex11.11.o function.o -o ex11.11

ex11.11.o: ex11.11.c
	$(CC) -c ex11.11.c

function.o: function.c function.h
	$(CC) -c function.c

clean:
	rm -f ex11.1 ex11.2 ex11.3 ex11.4 ex11.5 ex11.6 ex11.7 ex11.8 ex11.9 ex11.10\
		ex11.11 ex11.12 ex11.13 ex11.14 ex11.15 ex11.16
	rm -f *.o
