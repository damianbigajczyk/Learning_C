# -*- MakeFile -*-
#  Usage:
#  make 	# compile all binary
#  make clean 	# remove all binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

BIN := $(patsubst %.c,%,$(wildcard ex17.*.c))

all: ${BIN}

ex17.2: ex17.2.o list_1.o
	$(CC) ex17.2.o list_1.o -o ex17.2

ex17.2.o: ex17.2.c
	$(CC) -c ex17.2.c

ex17.3: ex17.3.o list_2.o
	$(CC) ex17.3.o list_2.o -o ex17.3

ex17.3.o: ex17.3.c
	$(CC) -c ex17.3.c

ex17.4: ex17.4.o queue.o
	$(CC) ex17.4.o queue.o -o ex17.4

ex17.4.o: ex17.4.c
	$(CC) -c ex17.4.c

ex17.7: ex17.7.o wordsTree.o
	$(CC) ex17.7.o wordsTree.o -o ex17.7

ex17.7.o: ex17.7.c
	$(CC) -c ex17.7.c

ex17.8: ex17.8.o animalTree.o
	$(CC) ex17.8.o animalTree.o -o ex17.8

ex17.8.o: ex17.8.c
	$(CC) -c ex17.8.c

list_1.o: list_1.c list_1.h
	$(CC) -c list_1.c

list_2.o: list_2.c list_2.h
	$(CC) -c list_2.c

queue.o: queue.c queue.h
	$(CC) -c queue.c

wordsTree.o: wordsTree.c wordsTree.h
	$(CC) -c wordsTree.c

animalTree.o: animalTree.c animalTree.h
	$(CC) -c animalTree.c

clean:
	@echo "Cleaning up..."
	@$(RM)
