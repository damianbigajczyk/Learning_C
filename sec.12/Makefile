# -*- MakeFile -*-
#  Usage:
#  make 	# compile all binary
#  make clean 	# remove all binaries and objects

.PHONY : all clean

CC = gcc
CFLAGS = -Wall -g
RM = -rm -vf *.o ${BIN}

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(wildcard pe*.c))
BIN := $(filter-out $(OBJ:%.o=%), $(SRC:%.c=%))

all: ${BIN}
	
ex12.2: ex12.2.o pe12_2a.o
	$(CC) $(CFLAGS) ex12.2.o pe12_2a.o -o ex12.2

ex12.2.o: ex12.2.c
	$(CC) $(CFLAGS) -c ex12.2.c

pe12_2a.o: pe12_2a.c pe12_2a.h
	$(CC) $(CFLAGS) -c pe12_2a.c

ex12.3: ex12.3.o pe12_3.o
	$(CC) $(CFLAGS) ex12.3.o pe12_3.o -o ex12.3

ex12.3.o: ex12.3.c
	$(CC) $(CFLAGS) -c ex12.3.c

pe12_3.o: pe12_3.c pe12_3.h
	$(CC) $(CFLAGS) -c pe12_3.c

ex12.5: ex12.5.o pex12_5.o
	$(CC) $(CLFAGS) ex12.5.o pex12_5.o -o ex12.5

ex12.5.o: ex12.5.c
	$(CC) $(CFLAGS) -c ex12.5.c

pex12_5.o: pex12_5.c pex12_5.h
	$(CC) $(CFLAGS) -c pex12_5.c

ex12.7: ex12.7.o pex12_7.o
	$(CC) $(CFLAGS) ex12.7.o pex12_7.o -o ex12.7

ex12.7.o: ex12.7.c
	$(CC) $(CFLAGS) -c ex12.7.c

pex12_7.o: pex12_7.c pex12_7.h
	$(CC) $(CFLAGS) -c pex12_7.c

ex12.9: ex12.9.o pex12_9.o
	$(CC) $(CFLAGS) ex12.9.o pex12_9.o -o ex12.9

ex12.9.o: ex12.9.c
	$(CC) $(CFLAGS) -c ex12.9.c

pex12_9.o: pex12_9.c pex12_9.h
	$(CC) $(CFLAGS) -c pex12_9.c

clean:
	@echo "Cleaning up..."
	@$(RM)
