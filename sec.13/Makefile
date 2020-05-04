# -*- MakeFIle -*-

CC = gcc
CFLAGS = -Wall -g

all: ex13.1 ex13.2 ex13.3 ex13.4 ex13.5 ex13.6 ex13.7 ex13.7b ex13.8 ex13.9\
	ex13.10 ex13.11 ex13.12 ex13.13


ex13.5: ex13.5.o pex13.5.o
	$(CC) ex13.5.o pex13.5.o

ex13.5.o: ex13.5.c
	$(CC) -c ex13.5.c

pex13.5.o: pex13.5.c pex13_5.h
	$(CC) -c pex13.5.c

clean:
	rm -f ex13.1 ex13.2 ex13.3 ex13.4 ex13.5 ex13.6 ex13.7 ex13.7b ex13.8 ex13.9\
		ex13.10 ex13.11 ex13.12 ex13.13
	rm -f *.o
