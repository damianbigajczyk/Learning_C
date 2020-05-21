# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

all: ex15.1 ex15.2 ex15.3 ex15.4 ex15.5 ex15.6 ex15.7

ex15.1: ex15.1.o function.o
	$(CC) ex15.1.o function.o -o ex15.1

ex15.1.o: ex15.1.c
	$(CC) -c ex15.1.c

ex15.2: ex15.2.o function.o
	$(CC) ex15.2.o function.o -o ex15.2

ex15.2.o: ex15.2.c
	$(CC) -c ex15.2.c

ex15.3: ex15.3.o function.o
	$(CC) ex15.3.o function.o -o ex15.3

ex15.3.o: ex15.3.c
	$(CC) -c ex15.3.c

ex15.4: ex15.4.o function.o
	$(CC) ex15.4.o function.o -o ex15.4

ex15.4.o: ex15.4.c
	$(CC) -c ex15.4.c

ex15.5: ex15.5.o function.o
	$(CC) ex15.5.o function.o -o ex15.5

ex15.5.o: ex15.5.c
	$(CC) -c ex15.5.c

ex15.6: ex15.6.o function.o
	$(CC) ex15.6.o function.o -o ex15.6

ex15.6.o: ex15.6.c
	$(CC) -c ex15.6.c

ex15.7: ex15.7.o font.o
	$(CC) ex15.7.o font.o -o ex15.7

ex15.7.o: ex15.7.c
	$(CC) -c ex15.7.c

font.o: font.c font.h
	$(CC) -c font.c

function.o: function.c function.h
	$(CC) -c function.c

clean:
	rm -f *.o
	rm -f ex15.1 ex15.2 ex15.3 ex15.4 ex15.5 ex15.6 ex15.7
