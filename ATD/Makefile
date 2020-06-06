# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -g

all: movies queueMain binaryTree

movies: movies.o linkedList.o
	$(CC) movies.o linkedList.o -o movies

movies.o: movies.c
	$(CC) -c movies.c

linkedList.o: linkedList.c linkedList.h
	$(CC) -c linkedList.c

queueMain: queueMain.o queue.o
	$(CC) queueMain.o queue.o -o queueMain

queueMain.o: queueMain.c
	$(CC) -c queueMain.c

queue.o: queue.c queue.h
	$(CC) -c queue.c

binaryTree: binaryTree.o tree.o
	$(CC) binaryTree.o tree.o -o binaryTree

binaryTree.o: binaryTree.c
	$(CC) -c binaryTree.c

tree.o: tree.c tree.h
	$(CC) -c tree.c

clean:
	rm -f *.o
	rm -f movies queueMain binaryTree

