# -*- MakeFile -*-
#  Usage:
#  make		# compile all binary
#  make clean	# remove all binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

BIN := $(patsubst %.c,%,$(wildcard ex14.*.c))

all: ${BIN}

ex14.1: ex14.1.o function.o
	$(CC) ex14.1.o function.o -o ex14.1

ex14.1.o: ex14.1.c
	$(CC) -c ex14.1.c

ex14.2: ex14.2.o function.o
	$(CC) ex14.2.o function.o -o ex14.2

ex14.2.o: ex14.2.c
	$(CC) -c ex14.2.c

ex14.3: ex14.3.o function.o
	$(CC) ex14.3.o function.o -o ex14.3

ex14.3.o: ex14.3.c
	$(CC) -c ex14.3.c

ex14.4: ex14.4.o function.o
	$(CC) ex14.4.o function.o -o ex14.4

ex14.4.o: ex14.4.c
	$(CC) -c ex14.4.c

ex14.5: ex14.5.o function.o
	$(CC) ex14.5.o function.o -o ex14.5

ex14.5.o: ex14.5.c
	$(CC) -c ex14.5.c

ex14.6: ex14.6.o function_6.o
	$(CC) ex14.6.o function_6.o -o ex14.6

ex14.6.o: ex14.6.c
	$(CC) -c ex14.6.c

ex14.7: ex14.7.o function.o
	$(CC) ex14.7.o function.o -o ex14.7

ex14.7.o: ex14.7.c
	$(CC) -c ex14.7.c

ex14.8: ex14.8.o colossus.o
	$(CC) ex14.8.o colossus.o -o ex14.8

ex14.8.o: ex14.8.c
	$(CC) -c ex14.8.c

colossus.o: colossus.c colossus.h
	$(CC) -c colossus.c

ex14.9: ex14.9.o colossus_2.o
	$(CC) ex14.9.o colossus_2.o -o ex14.9

ex14.9.o: ex14.9.c
	$(CC) -c ex14.9.c

colossus_2.o: colossus_2.c colossus_2.h
	$(CC) -c colossus_2.c

function_6.o: function_6.c function_6.h
	$(CC) -c function_6.c

function.o: function.c function.h
	$(CC) -c function.c

ex14.10: ex14.10.c
	$(CC) ex14.10.c -o ex14.10 -lm

clean:
	@echo "Cleaning up..."
	@$(RM)
