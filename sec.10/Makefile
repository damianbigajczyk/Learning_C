# -*- MakeFile -*-

CC = gcc
CFALGS = -Wall -g

all: ex10.1 ex10.2 ex10.3 ex10.4 ex10.5 ex10.6 ex10.7 ex10.8 ex10.9 ex10.10 ex10.11 ex10.12 ex10.13

ex10.1: ex10.1.o function.o
	$(CC) ex10.1.o function.o -o ex10.1

ex10.1.o: ex10.1.c
	$(CC) -c ex10.1.c

ex10.2: ex10.2.o function.o
	$(CC) ex10.2.o function.o -o ex10.2

ex10.2.o: ex10.2.c
	$(CC) -c ex10.2.c

ex10.3: ex10.3.o function.o
	$(CC) ex10.3.o function.o -o ex10.3

ex10.3.o: ex10.3.c
	$(CC) -c ex10.3.c

ex10.4: ex10.4.o function.o
	$(CC) ex10.4.o function.o -o ex10.4

ex10.4.o: ex10.4.c
	$(CC) -c ex10.4.c

ex10.5: ex10.5.o function.o
	$(CC) ex10.5.o function.o -o ex10.5

ex10.5.o: ex10.5.c
	$(CC) -c ex10.5.c

ex10.6: ex10.6.o function.o
	$(CC) ex10.6.o function.o -o ex10.6

ex10.6.o: ex10.6.c
	$(CC) -c ex10.6.c

ex10.7: ex10.7.o function.o
	$(CC) ex10.7.o function.o -o ex10.7

ex10.7.o: ex10.7.c
	$(CC) -c ex10.7.c

ex10.8: ex10.8.o function.o
	$(CC) ex10.8.o function.o -o ex10.8

ex10.8.o: ex10.8.c
	$(CC) -c ex10.8.c

ex10.9: ex10.9.o function.o
	$(CC) ex10.9.o function.o -o ex10.9

ex10.9.o: ex10.9.c
	$(CC) -c ex10.9.c

ex10.10: ex10.10.o function.o
	$(CC) ex10.10.o function.o -o ex10.10

ex10.10.o: ex10.10.c
	$(CC) -c ex10.10.c

ex10.12: ex10.12.o function.o
	$(CC) ex10.12.o function.o -o ex10.12

ex10.12.o: ex10.12.c
	$(CC) -c ex10.12.c

ex10.13: ex10.13.o function.o
	$(CC) ex10.13.o function.o -o ex10.13

ex10.13.o: ex10.13.c
	$(CC) -c ex10.13.c

function.o: function.c function.h
	$(CC) -c function.c

clean:
	rm -f ex10.1 ex10.2 ex10.3 ex10.4 ex10.5 ex10.6 ex10.7 ex10.8 ex10.9 ex10.10 ex10.11 ex10.12 ex10.13
	rm -f *.o
