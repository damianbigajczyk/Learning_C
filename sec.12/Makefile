# -*- MakeFile -*-

# select the compiler and flags
CC = gcc
CFLAGS = -Wall -g

all: ex12.1 ex12.2 ex12.3 ex12.4 ex12.5 ex12.6 ex12.7 ex12.8 ex12.9

ex12.2: ex12.2.o pe12_2a.o
	$(CC) ex12.2.o pe12_2a.o -o ex12.2

ex12.2.o: ex12.2.c
	$(CC) -c ex12.2.c

pe12_2a.o: pe12_2a.c pe12_2a.h
	$(CC) -c pe12_2a.c

ex12.3: ex12.3.o pe12_3.o
	$(CC) ex12.3.o pe12_3.o -o ex12.3

ex12.3.o: ex12.3.c
	$(CC) -c ex12.3.c

pe12_3.o: pe12_3.c pe12_3.h
	$(CC) -c pe12_3.c

ex12.5: ex12.5.o pex12_5.o
	$(CC) ex12.5.o pex12_5.o -o ex12.5

ex12.5.o: ex12.5.c
	$(CC) -c ex12.5.c

pex12_5.o: pex12_5.c pex12_5.h
	$(CC) -c pex12_5.c

ex12.7: ex12.7.o pex12_7.o
	$(CC) ex12.7.o pex12_7.o

ex12.7.o: ex12.7.c
	$(CC) -c ex12.7.c

pex12_7.o: pex12_7.c pex12_7.h
	$(CC) -c pex12_7.c

ex12.9: ex12.9.o pex12_9.o
	$(CC) ex12.9.o pex12_9.o

ex12.9.o: ex12.9.c
	$(CC) -c ex12.9.c

pex12_9.o: pex12_9.c pex12_9.h
	$(CC) -c pex12_9.c

clean:
	rm -f ex12.1 ex12.2 ex12.3 ex12.4 ex12.5 ex12.6 ex12.7 ex12.8 ex12.9
	rm -f *.o

