# -*- MakeFIle -*-
#  Usage:
#  make		# compile all binary
#  make clean	# remove all binaries and objects

.PHONY : all clear

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

SRC := $(filter-out pex13.5.c, $(wildcard *.c))
BIN := $(SRC:%.c=%)

all: ${BIN}

ex13.5: ex13.5.o pex13.5.o
	$(CC) $(CFLAGS) ex13.5.o pex13.5.o -o ex13.5

ex13.5.o: ex13.5.c
	$(CC) $(CFLAGS) -c ex13.5.c

pex13.5.o: pex13.5.c pex13_5.h
	$(CC) $(CFLAGS) -c pex13.5.c

clean:
	@echo "Cleaning up..."
	@$(RM)
